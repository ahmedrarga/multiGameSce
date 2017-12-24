int perecenesnakes(int countsnak,int countcard)
{
    float percenesnakes;
    percenesnakes=(float(countsnak)/(countcard+countsnak));
    return static_cast<int>(percenesnakes*100);
}