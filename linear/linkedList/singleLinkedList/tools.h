void clearScreen()
{
    printf("\n\n(press any key to continue . . .)");
    getch();
    system("cls");
}

void justClear()
{
    system("cls");
}

void terminate()
{
    printf("Program Terminated!! Thank you . . .\n(Press any key to exit.)");
    getch();
    exit(0);
}
