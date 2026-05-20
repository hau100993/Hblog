// #include <stdio.h>
// #include <iostream>
#include <bits/stdc++.h>

// #pragma message("Test FIle IO IO")

void readFile()
{
    //open file 
    FILE* fd = fopen("file_text.txt", "r");
    if(!fd)
        printf("Can not open file\n");

    // read and printf 
    char buf[100]; 
    buf[0] = '\n';
    /* method 1 */
    // while (fgets(buf, sizeof(buf), fd))
    // {
    //     std::cout << buf; 
    //     /* code */
    // }

    while (!feof(fd))
    {
        // fscanf(fd, "*s %d", buf);
        fread(buf, sizeof(buf), 1, fd); 
        std::cout << buf << "\n";
        /* code */
    }
    return; 

}


int main()
{

    // printf("Hello\n");
    readFile();
    return 0; 
}
