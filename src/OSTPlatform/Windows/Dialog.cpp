#include "include/Dialog.h"

#include <windows.h>

namespace OSTPlatform::Dialog {

static std::wstring Utf8ToUtf16(const std::string& str) {
    if (str.empty()) return L"";
    int size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), nullptr, 0);
    std::wstring result(size, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), &result[0], size);
    return result;
}

void ShowWarning(std::string title, std::string message) {
    MessageBoxW(nullptr, Utf8ToUtf16(message).c_str(), Utf8ToUtf16(title).c_str(), MB_OK | MB_ICONWARNING | MB_TOPMOST);
}

void ShowInfo(std::string title, std::string message) {
    MessageBoxW(nullptr, Utf8ToUtf16(message).c_str(), Utf8ToUtf16(title).c_str(), MB_OK | MB_ICONINFORMATION | MB_TOPMOST);
}

bool ShowConfirm(std::string title, std::string message) {
    return MessageBoxW(nullptr, Utf8ToUtf16(message).c_str(), Utf8ToUtf16(title).c_str(),
                       MB_YESNO | MB_ICONINFORMATION | MB_TOPMOST) == IDYES;
}

} // namespace OSTPlatform::Dialog
