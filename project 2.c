#include <stdio.h>
#include <string.h>

#define MAX 50

int main() {
    int id[MAX], avail[MAX], count = 0, choice, i, target, found;
    char name[MAX][30], author[MAX][30], cat[MAX][30];
    float price[MAX];

    do {
        printf("\n--- LIBRARY MANAGEMENT SYSTEM ---\n");
        printf("1. Add Book\n2. Display All\n3. Search ID\n4. Search Name\n5. Issue\n6. Return\n7. Update\n8. Count\n9. Available\n10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (count >= MAX) { printf("Library Full!\n"); break; }
                printf("Enter ID: "); scanf("%d", &id[count]);
                for(i=0; i<count; i++) {
                    if(id[i] == id[count]) { printf("Duplicate ID!\n"); break; }
                }
                if(i < count) break;
                
                getchar();
                printf("Name: "); fgets(name[count], 30, stdin); name[count][strcspn(name[count], "\n")] = 0;
                printf("Author: "); fgets(author[count], 30, stdin); author[count][strcspn(author[count], "\n")] = 0;
                printf("Category: "); fgets(cat[count], 30, stdin); cat[count][strcspn(cat[count], "\n")] = 0;
                printf("Price: "); scanf("%f", &price[count]);
                avail[count] = 1;
                count++;
                printf("Added successfully!\n");
                break;

            case 2:
                for(i=0; i<count; i++) {
                    printf("\nID: %d | Name: %s | Author: %s | Status: %s\n", id[i], name[i], author[i], avail[i] ? "Available" : "Issued");
                }
                break;

            case 3:
                printf("Enter ID: "); scanf("%d", &target);
                found = 0;
                for(i=0; i<count; i++) {
                    if(id[i] == target) {
                        printf("Found: %s by %s\n", name[i], author[i]);
                        found = 1; break;
                    }
                }
                if(!found) printf("Not found!\n");
                break;

            case 4:
                {
                    char targetName[30];
                    getchar();
                    printf("Enter Name: "); fgets(targetName, 30, stdin); targetName[strcspn(targetName, "\n")] = 0;
                    found = 0;
                    for(i=0; i<count; i++) {
                        if(strcasecmp(name[i], targetName) == 0) {
                            printf("Found ID: %d\n", id[i]);
                            found = 1;
                        }
                    }
                    if(!found) printf("Not found!\n");
                }
                break;

            case 5:
                printf("Enter ID to issue: "); scanf("%d", &target);
                for(i=0; i<count; i++) {
                    if(id[i] == target) {
                        if(avail[i]) { avail[i] = 0; printf("Issued successfully!\n"); }
                        else printf("Already issued!\n");
                        break;
                    }
                }
                break;

            case 6:
                printf("Enter ID to return: "); scanf("%d", &target);
                for(i=0; i<count; i++) {
                    if(id[i] == target) {
                        if(!avail[i]) { avail[i] = 1; printf("Returned successfully!\n"); }
                        else printf("Already available!\n");
                        break;
                    }
                }
                break;

            case 7:
                printf("Enter ID to update: "); scanf("%d", &target);
                for(i=0; i<count; i++) {
                    if(id[i] == target) {
                        getchar();
                        printf("New Name: "); fgets(name[i], 30, stdin); name[i][strcspn(name[i], "\n")] = 0;
                        printf("New Price: "); scanf("%f", &price[i]);
                        printf("Updated!\n");
                        break;
                    }
                }
                break;

            case 8:
                printf("Total books: %d\n", count);
                break;

            case 9:
                for(i=0; i<count; i++) {
                    if(avail[i]) printf("ID: %d, Name: %s\n", id[i], name[i]);
                }
                break;

            case 10:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 10);

    return 0;
}


output:

--- LIBRARY MANAGEMENT SYSTEM ---
1. Add Book
2. Display All
3. Search ID
4. Search Name
5. Issue
6. Return
7. Update
8. Count
9. Available
10. Exit
Enter choice: 1
Enter ID: 101
Name: C Programming
Author: E. Balagurusamy
Category: Programming
Price: 450
Added successfully!

--- LIBRARY MANAGEMENT SYSTEM ---
1. Add Book
2. Display All
3. Search ID
4. Search Name
5. Issue
6. Return
7. Update
8. Count
9. Available
10. Exit
Enter choice: 2

ID: 101 | Name: C Programming | Author: E. Balagurusamy | Status: Available

--- LIBRARY MANAGEMENT SYSTEM ---
1. Add Book
2. Display All
3. Search ID
4. Search Name
5. Issue
6. Return
7. Update
8. Count
9. Available
10. Exit
Enter choice: 5
Enter ID to issue: 101
Issued successfully!

--- LIBRARY MANAGEMENT SYSTEM ---
1. Add Book
2. Display All
3. Search ID
4. Search Name
5. Issue
6. Return
7. Update
8. Count
9. Available
10. Exit
Enter choice: 10
Exiting...