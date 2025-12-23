#include<iostream>
#include<iomanip> // สำหรับการใช้งาน setw(), setprecision(), fixed
using namespace std;

int main() {
    double loan, rate, payPerYear;

    // รับค่าจากผู้ใช้
    cout << "Enter initial loan: ";
    cin >> loan;
    cout << "Enter interest rate per year (%): ";
    cin >> rate;
    cout << "Enter amount you can pay per year: ";
    cin >> payPerYear;

    // แสดงหัวตาราง
    cout << setw(13) << left << "EndOfYear#"; 
    cout << setw(13) << left << "PrevBalance"; 
    cout << setw(13) << left << "Interest"; 
    cout << setw(13) << left << "Total";
    cout << setw(13) << left << "Payment";
    cout << setw(13) << left << "NewBalance";
    cout << "\n";

    double prevBalance = loan;
    int year = 1;

    // ตั้งค่าทศนิยม 2 ตำแหน่ง
    cout << fixed << setprecision(2);

    while (prevBalance > 0) {
        double interest = prevBalance * (rate / 100.0);
        double total = prevBalance + interest;
        double payment;

        // ตรวจสอบว่าเป็นปีสุดท้ายหรือไม่
        if (total < payPerYear) {
            payment = total;
        } else {
            payment = payPerYear;
        }

        double newBalance = total - payment;

        // แสดงผลในแต่ละปี
        cout << setw(13) << left << year;
        cout << setw(13) << left << prevBalance;
        cout << setw(13) << left << interest;
        cout << setw(13) << left << total;
        cout << setw(13) << left << payment;
        cout << setw(13) << left << newBalance;
        cout << "\n";

        // อัปเดตค่าสำหรับปีถัดไป
        prevBalance = newBalance;
        year++;
        
        // กัน Loop ไม่สิ้นสุดในกรณีที่ดอกเบี้ยสูงกว่าเงินที่จ่ายไหว
        if(interest >= payPerYear && prevBalance > 0){
            cout << "\n[Warning: The interest is higher than payment. You will never pay off the debt!]" << endl;
            break;
        }
    }

    return 0;
}
