#include <iostream>;
using namespace std;
// mô tả số hạng
struct sohang {
	float heso;
	int somu;
	sohang *next;
};
// hàm tạo ra số hạng mới
sohang* taosohang(float a, int b) {
	sohang *sohangmoi = new sohang;
	sohangmoi->heso = a;
	sohangmoi->somu = b;
	sohangmoi->next = nullptr;
	return sohangmoi;
}

// hàm thêm số hạng vào đa thức thứ tự mũ giảm dần
void themsohang(sohang*& head, float a, int b) {
	if (a == 0) return; // he so = 0 khoong them
	sohang* sohangmoi = taosohang(a, b); // tạo ra chuỗi số hạng chứa các hệ số và số mũ 
	// chèn vào đâu danh sách
	if (head == nullptr || b > head->somu) {
		sohangmoi->next = head;
		head = sohangmoi;
	}
	
	// chèn giữa
	else {
		sohang* hientai = head;
		while (hientai->next != nullptr && hientai->next->somu >= b) {
			hientai = hientai->next;
		}

		// mux bằng thì cộng hệ số
		if (hientai->somu == b) {
			hientai->heso += a;
			delete sohangmoi; // xóa vì số hạng mới đã cộng vào số hạng hiện tại

		}
		else {
			sohangmoi->next = hientai->next;
			hientai->next = sohangmoi;
		}
	}
}
void indathuc(sohang* ronaldo) {
	if (ronaldo == nullptr) {
		cout << "0";
		return;
	}
	while (ronaldo != nullptr) {
		cout << (ronaldo->heso > 0 ? "+" : " ") << ronaldo->heso << "x^" << ronaldo->somu << " ";
		ronaldo = ronaldo->next;
	}
	cout << endl;

}

// cộng đa thức
sohang* congdathuc(sohang* dt1, sohang* dt2) {
	sohang* kq = nullptr;
	while (dt1 != nullptr) {
		themsohang(kq, dt1->heso, dt1->somu); // su dung hamf them so hang de them so hang vao kq
		dt1 = dt1->next;
	}
	while (dt2 != nullptr) {
		themsohang(kq, dt2->heso, dt2->somu);
		dt2 = dt2->next;
	}
	return kq;
}


int main() {
	sohang* dt1 = nullptr;
	sohang* dt2 = nullptr;
	int n1, n2;
	float heso;
	int somu;

	//nhap da thuc 1
	cout << "NHAP DA THUC THU NHAT" << endl;
	cout << "Ban muon nhap bao nhieu so hang:";
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cout << "Nhap he so va so mu cua so hang thu " << i + 1 << ": ";
		cin >> heso >> somu;
		themsohang(dt1, heso, somu);
	}

	//nhap da thuc 2
	cout << endl;
	cout << "NHAP DA THUC THU HAI" << endl;
	cout << "Ban muon nhap bao nhieu so hang:";
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cout << "Nhap he so va so mu cua so hang thu " << i + 1 << ": ";
		cin >> heso >> somu;
		themsohang(dt2, heso, somu);
	}

	//in da thuc
	cout << endl;
	cout << "DA THUC THU NHAT: ";
	indathuc(dt1);
	cout << endl;
	cout << "DA THUC THU HAI: ";
	indathuc(dt2);


	//cong da thuc
	sohang* dathuctong = congdathuc(dt1, dt2);
	cout << endl;
	cout << "DA THUC TONG: ";
	indathuc(dathuctong);

	return 0;
}