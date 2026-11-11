#include <format>
#include <map>
#include <optional>
#include <print>
#include <string>
#include <span>

typedef struct ArgFlagData {
  std::string description;
  std::optional<std::string> data;
} ArgFlagData;

std::map<std::string, ArgFlagData> arg_flags = {
    {"-f", ArgFlagData{.description = "file"}}};

typedef struct CliArgs {
  std::optional<std::string> file_path;
} CliArgs;

void logError(std::string msg) { std::println("[error] {:s}", msg); }

void parseArgs(int argc, char *args[]) {
  for (size_t i = 0; i < argc; i++) {
    try {
      ArgFlagData arg_flag_data = arg_flags.at(args[i]);
      arg_flag_data.data = args[i + 1];
      arg_flags.at(args[i]) = arg_flag_data;
      i++;
    } catch (const std::exception &e) {
      logError(std::format("flag '{:s}' not found", args[i]));
    }
  }
}

int main(int argc, char *argv[]) {
    std::span args{argv, static_cast<std::size_t>(argc)};
    parseArgs(argc - 1, args.subspan(1).data());
    ArgFlagData data = arg_flags.at("-f");
    std::print("{:s}", data.data.value_or("build.toml"));
    return 0;
}
