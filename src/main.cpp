#include "bindings.h"
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <stringapiset.h>
#include <winnls.h>

using namespace std;

std::string ConvertWideToUTF8(const std::wstring &wstr) {
  int count = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), wstr.length(), NULL,
                                  0, NULL, NULL);
  std::string str(count, 0);
  WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], count, NULL, NULL);
  return str;
}

std::wstring ConvertACPToWide(const char *str) {
  if (!str || strlen(str) == 0) {
    return {};
  }

  int count = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
  std::wstring wstr(count, 0);
  MultiByteToWideChar(CP_ACP, 0, str, -1, &wstr[0], count);
  return wstr;
}

int main(int argc, char **argv) {
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      remove_dir(ConvertWideToUTF8(ConvertACPToWide(argv[i])).c_str());
    }
    system("pause");
    return 0;
  }

  string input;
  while (getline(cin, input)) {
    auto path = ConvertWideToUTF8(ConvertACPToWide(input.c_str()));
    remove_dir(path.c_str());
  }
  return 0;
}
