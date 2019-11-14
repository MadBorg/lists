Name - Url of repo:
    https://github.uio.no/IN1910/H19_project2_nablisog_sanders.git
Commands for compiling:
    Array_list.cpp:
        ~\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe -g ~\H19_project2_nablisog_sanders\array_list.cpp -o ~\H19_project2_nablisog_sanders\bin\array_list.exe
    Linked list:
        ~\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe -g ~\H19_project2_nablisog_sanders\linked_list.cpp -o ~\H19_project2_nablisog_sanders\bin\linked_list.exe
    Cirular_linked_list.cpp:
        ~\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe' -g ~\H19_project2_nablisog_sanders\circular_linked_list.cpp -o     ~\H19_project2_nablisog_sanders\bin\circular_linked_list.exe

A ist of execises that we managed to compile and run.
    1a-1j, 2a-2d, 3, 4a-4g.

Task 3 - Big O
Linked_list (head, tail):
    *get_node(int): O(n/2)
    push_front(int): O(1)
    push_back(int): O(1)
    LinkedList(vector<int>): O(n)
    ~LinkedList(): O(n)
    operator[](int): get_node(int)
    append(int): push_back(int)
    insert(int, int): get_node(int)
    remove(int): get_node(int)
    pop(): remove(-1): O(1)
    pop(index): get_node(int) + remove(int): O(n/2 + n/2): O(n)
    print(): O(n)

ArrayList:
    resize(): O(3n)
    ArrayList(vector<int>): O(n)
    ~LinkedList: O(1)
    get(int): O(n)
    append(int): if size > capacity then O(2n): , else O(n)
    insert(int, int): O(4n)
    remove(int): O(3n) + pop(): O(4n)
    pop(): O(n)
    pop(int): O(n) + remove(int): O(5)
    print(): O(3)
    shrink_to_fit(): O(n) + 2*n(append(int)+get(int)) = O(7n)

Task 4g
    last man standing is 68.
