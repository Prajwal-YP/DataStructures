//tools
void mssgClear()
{
    printf("\n(Press any key to continue . . .)");
    getch();
    system("cls");
}

void justClear()
{
    system("cls");
}

void terminate()
{
    printf("\n\nProgram Terminated!!");
    mssgClear();
    exit(0);
}
