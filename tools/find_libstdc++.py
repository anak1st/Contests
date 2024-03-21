import os

def color_print(text, color):
    if color == "red":
        return "\033[31m" + text + "\033[0m"
    elif color == "green":
        return "\033[32m" + text + "\033[0m"
    elif color == "yellow":
        return "\033[33m" + text + "\033[0m"
    elif color == "blue":
        return "\033[34m" + text + "\033[0m"
    elif color == "purple":
        return "\033[35m" + text + "\033[0m"
    else:
        return text


def get_path():
    path = os.environ.get('PATH')
    # print(path)
    path = path.split(';')

    for i in range(len(path)):
        if path[i].startswith("%"):
            path[i] = os.environ.get(path[i][1:-1])

        path[i] = path[i].replace("\\", "/")

    path_unique = []
    for i in range(len(path)):
        if path[i] not in path_unique:
            path_unique.append(path[i])
    
    return path_unique


def find_bin(path, name):
    fullname = path[i] + "/"
    match name:
        case "gcc" | "clang" | "python" | "git" | "perl":
            fullname += name + ".exe"

        case "nodejs":
            fullname += "node.exe"

        case "rust":
            fullname += "rustc.exe"

        case "cuda":
            fullname += "nvcc.exe"

        case "latex":
            fullname += "pdflatex.exe"

        case "mingw":
            fullname += "libstdc++-6.dll"

        case _:
            return False

    return os.path.exists(fullname)


if __name__ == '__main__':
    path = get_path()
    vis = {}
    names = ["mingw", "gcc", "clang", "python", "nodejs", "rust", "cuda", "git", "perl", "latex"]

    for i in range(len(path)):
        text = path[i]
        find_some = False

        for name in names:
            if find_bin(path, name):
                find_some = True

                if name not in vis:
                    text += " (" + color_print(name, "red") + ")"
                    vis[name] = True
                else:
                    text += " (" + color_print(name, "green") + ")"

        idx = f"{i + 1:3d}"
        if find_some:
            idx = color_print(idx, "yellow")

        print(f"[{idx}] {text}")

