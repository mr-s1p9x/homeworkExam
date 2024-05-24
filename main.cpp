#include <iostream>
#include <cwctype>
#include <codecvt>

using namespace std;

// Функция фильтрации текста
void filterText(wchar_t* text, bool filterLatin, bool filterCyrillic, bool filterPunctuation, bool filterDigits) {
    for (int i = 0; text[i] != L'\0'; ++i) {
        wchar_t c = text[i];
        // Проверка на латинские символы
        if (filterLatin && ((c >= L'a' && c <= L'z') || (c >= L'A' && c <= L'Z'))) {
            text[i] = L' ';
        }
        // Проверка на символы кириллицы
        if (filterCyrillic && ((c >= L'А' && c <= L'Я') || (c >= L'а' && c <= L'я'))) {
            text[i] = L' ';
        }
        // Проверка на символы пунктуации
        if (filterPunctuation && iswpunct(c)) {
            text[i] = L' ';
        }
        // Проверка на цифры
        if (filterDigits && iswdigit(c)) {
            text[i] = L' ';
        }
    }
}

int main() {
    // Устанавливаем локаль для корректной работы с широкими символами
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());

    // Остальной код программы
    wchar_t text[] = L"Пример текста 1234, с различными символами ABC, @!#";
    wcout << L"Оригинальный текст: " << text << endl;
    // меняя true/false выбираем нужные фильтры
    filterText(text, false, true, false, true);
    wcout << L"Отфильтрованный текст: " << text << endl;

    return 0;
}



