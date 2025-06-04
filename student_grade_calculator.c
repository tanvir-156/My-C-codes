#include <stdio.h>

float calculateClassTestAverage(int ct1, int ct2, int ct3) {
    int sum = ct1 + ct2 + ct3;
    int minCt = (ct1 < ct2) ? (ct1 < ct3 ? ct1 : ct3) : (ct2 < ct3 ? ct2 : ct3);
    return (sum - minCt) / 2.0;
}

char calculateGrade(float totalMarks) {
    if (totalMarks >= 90) return 'A';
    if (totalMarks >= 80) return 'B';
    if (totalMarks >= 70) return 'C';
    if (totalMarks >= 60) return 'D';
    return 'F';
}

int main() {
    int T;
    scanf("%d", &T);

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int term1, term2, finalExam, attendance, ct1, ct2, ct3;
        scanf("%d %d %d %d %d %d %d", &term1, &term2, &finalExam, &attendance, &ct1, &ct2, &ct3);

        if (term1 > 20 || term2 > 20 || finalExam > 30 || attendance > 10 ||
            ct1 > 20 || ct2 > 20 || ct3 > 20) {
            printf("Invalid input\n");
            continue;
        }

        float classTestAverage = calculateClassTestAverage(ct1, ct2, ct3);
        float totalMarks = term1 * 1.0 + term2 * 1.0 + finalExam * 1.0 + attendance * 1.0 + classTestAverage;
        char grade = calculateGrade(totalMarks);
        printf("Case %d: %c\n", caseNum, grade);
    }

    return 0;
}
