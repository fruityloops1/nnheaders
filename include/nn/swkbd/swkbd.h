#pragma once

#include <cstdlib>
#include <nn/types.h>

namespace nn::swkbd {

enum class Preset {
    Default,
    Password,
    UserName,
    DownloadCode,
    Max_Preset,
};

enum class KeyboardMode {
    ModeLanguageSet1,
    ModeNumeric,
    ModeASCII,
    ModeLanguageSet1Latin,
    ModeAlphabet,
    ModeSimplifiedChinese,
    ModeTraditionalChinese,
    ModeKorean,
    ModeLanguageSet2,
    ModeMax_KeyboardMode,
    ModeFull,
    ModeFullLatin,
};

enum class InvalidChar {
    Space = 1 << 1,
    AtMark = 1 << 2,
    Percent = 1 << 3,
    Slash = 1 << 4,
    BackSlash = 1 << 5,
    Numeric = 1 << 6,
    OutsideOfDownloadCode = 1 << 7,
    OutsideOfMiiNickName = 1 << 8,
    Force32 = 1 << 9,
};

enum class PasswordMode {
    Show,
    Hide,
    Max_PasswordMode,
};

enum class InputFormMode {
    OneLine,
    MultiLine,
    Separate,
    Max_InputFormMode,
};

enum class InitialCursorPos {
    First,
    Last,
    Max_InitialCursorPos,
};

enum class TextCheckResult {
    Success,
    ShowFailureDialog,
    ShowConfirmDialog,
    Max_TextCheckResult,
};

enum class DictionaryLang {
    Japanese,
    AmericanEnglish,
    CanadianFrench,
    LatinAmericanSpanish,
    Reserved1,
    BritishEnglish,
    French,
    German,
    Spanish,
    Italian,
    Dutch,
    Portuguese,
    Russian,
    Reserved2,
    SimplifiedChinesePinyin,
    TraditionalChineseCangjie,
    TraditionalChineseSimplifiedCangjie,
    TraditionalChineseZhuyin,
    Korean,
    Max_DictionaryLang,
};

struct DictionaryInfo {
    u32 offset;
    u16 size;
    DictionaryLang lang;
};

struct KeyboardConfig {
    KeyboardMode keyboardMode;
    char okText[0x12];
    char16_t leftOptionalSymbolKey;
    char16_t rightOptionalSymbolKey;
    bool isPredictionEnabled;
    InvalidChar invalidCharFlag;
    InitialCursorPos initialCursorPos;
    char headerText[0x82];
    char subText[0x102];
    char guideText[0x202];
    int textMaxLength;
    int textMinLength;
    PasswordMode passwordMode;
    InputFormMode inputFormMode;
    bool isUseNewLine;
    bool isUseUtf8;
    bool isUseBlurBackground;
    int _initialStringOffset;
    int _initialStringLength;
    int _userDictionaryOffset;
    int _userDictionaryNum;
    bool _isUseTextCheck;
    void* _textCheckCallback;
    int separateTextPos[0x8];
    u8 _410[208];
};

struct ShowKeyboardArg {
    KeyboardConfig keyboardConfig;
    u8* workBuf;
    long workBufSize;
    u8* textCheckWorkBuf;
    long textCheckWorkBufSize;
};

class String {
public:
    char16_t* strBuf;
    int bufSize;
};

struct UserWord;  // TODO contents missing

using TextCheckCallback = TextCheckResult (*)(void*, unsigned long*, String*);

ulong GetRequiredWorkBufferSize(bool);
ulong GetRequiredStringBufferSize();
ulong GetRequiredTextCheckWorkBufferSize();
void MakePreset(KeyboardConfig*, Preset);
void SetHeaderText(KeyboardConfig*, const char16_t*);
void SetSubText(KeyboardConfig*, const char16_t*);
void SetOkText(KeyboardConfig*, const char16_t*);
void SetOkTextUtf8(KeyboardConfig*, const char*);
void SetLeftOptionalSymbolKey(KeyboardConfig*, char16_t);
void SetLeftOptionalSymbolKeyUtf8(KeyboardConfig*, const char*);
void SetRightOptionalSymbolKey(KeyboardConfig*, char16_t);
void SetRightOptionalSymbolKeyUtf8(KeyboardConfig*, const char*);
void SetHeaderText(KeyboardConfig*, const char16_t*);
void SetHeaderTextUtf8(KeyboardConfig*, const char*);
void SetSubText(KeyboardConfig*, const char16_t*);
void SetSubTextUtf8(KeyboardConfig*, const char*);
void SetGuideText(KeyboardConfig*, const char16_t*);
void SetGuideTextUtf8(KeyboardConfig*, const char*);
void SetInitialText(ShowKeyboardArg*, const char16_t*);
void SetInitialTextUtf8(ShowKeyboardArg*, const char*);
void SetUserWordList(ShowKeyboardArg*, const UserWord*, int);
int ShowKeyboard(String*, const ShowKeyboardArg&);
void SetTextCheckCallback(ShowKeyboardArg* arg, TextCheckCallback callback);

}  // namespace nn::swkbd
