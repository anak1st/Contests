import os


def get_path():
    # for key, value in os.environ.items():
    #     print(key, ":=", value)
    
    path = os.environ.get('PATH')
    # print(path)
    path = path.split(';')

    for i in range(len(path)):
        if path[i].startswith("%"):
            path[i] = os.environ.get(path[i][1:-1])

        path[i] = path[i].replace("\\", "/")
    
    return path


def find_mingw(path):
    print("find_mingw:")
    for i in range(len(path)):
        find = 0

        if os.path.exists(path[i] + "/libstdc++-6.dll"):
            find = 1

        if os.path.exists(path[i] + "/libwinpthread-1.dll"):
            find = 1

        if os.path.exists(path[i] + "/libgcc_s_seh-1.dll"):
            find = 1

        if find == 1:
            print(path[i])


def find_python(path):
    print("find_python:")
    for i in range(len(path)):
        if os.path.exists(path[i] + "/python.exe"):
            print(path[i])


if __name__ == '__main__':
    path = get_path()
    find_mingw(path)
    find_python(path)
