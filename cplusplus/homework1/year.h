bool IsLeapYear(int year) {
    return year % 400 == 0 ? true : (year % 4 == 0) && (year % 100 != 0);
}

int DayByDate(int day, int month, int year) {
    int startWeekDay = 0;
    int days_in_months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int iYear = 1578; iYear <= year; ++iYear) {
        days_in_months[2] = IsLeapYear(iYear) ? 29 : 28;
        for(int iMonth = 1; (iMonth <= 12 && iYear < year) || (iMonth <= month && iYear == year); ++iMonth) {
            int lastDay = days_in_months[iMonth];
            for(int iDay = 1; (iDay <= lastDay && iYear < year) || (iDay <= lastDay && iMonth < month && iYear == year) || (iDay <= day && iMonth == month && iYear == year); ++iDay) {
                ++startWeekDay;
            }
        }
    }
    return (startWeekDay - 1) % 7;
}
