    #include <stdio.h>
     
    #define sizeDays 30
     
    int main () {
        int days[sizeDays], atualUsers, goalUsers, necessaryUsers, necessaryDays = 0, count_users = 0, median;
        float sum = 0;
     
        scanf("%d %d", &atualUsers, &goalUsers);
     
     
        for (int i = 0; i < sizeDays; ++i) {   
            scanf("%d", &days[i]);
            sum += days[i];
        }
        necessaryUsers = goalUsers - atualUsers; 
     
        while (count_users < necessaryUsers) {
            float a = sum / sizeDays;
            median = sum / sizeDays;
     
            if (median < a)
                median++;
     
            count_users += median;
     
            sum -= days[0];
            sum += median;
            for (int i=0; i< 29; i++) {
                days[i] = days[i+1];
            }
            days[29] = median;
     
            necessaryDays++; 
        }
     
        printf("%d", necessaryDays);
     
        return  0;
    }