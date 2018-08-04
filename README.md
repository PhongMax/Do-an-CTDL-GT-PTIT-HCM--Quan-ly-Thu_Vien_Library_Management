# QLTV-LIbrary-Management
Đồ án cá nhân  môn Cấu trúc dữ liệu và Giải thuật, Học Viên Công Nghê Bưu Chính Viễn Thông cơ sở TP HCM. //  code trên Visual Studio 2017.

" Có thể nói đây là môn khó nhất trường mình và là nỗi ác mộng của nhìu bạn sinh viên ngành CNTT khi người dạy là thầy Lưu Nguyễn Kỳ Thư. 1 lớp học 70 thì chỉ có tầm 10 bạn qua môn.
Đây là đồ án của mình được 8.5 với xử lí giao diện trên console c++ và bắt lỗi nghiệp vụ. Đồ án quản lý Thư Viện (đề tài 5 bên dưới)
Hi vọng giúp các bạn trường PTIT HCM được qua môn này... "        #nguồn: https://github.com/haint97/Do-an-CTDL-GT-PTIT-HCM--Quan-ly-may-bay ^^

// Trong đồ án này Mình có tham khảo một vài đồ án của các a/c khóa trước, Hi vọng các link này cũng sẽ là nguồn hữu ích nữa cho cách bạn tham khảo... 

+ https://github.com/haint97/Do-an-CTDL-GT-PTIT-HCM--Quan-ly-may-bay  // ý tưởng sự lý nghiệp vụ trong đồ án của anh này rất hay.
+ https://github.com/tuanseo 
+ https://github.com/tahongtrung/quanlidiemsv

P/S : Không ai có thể làm đồ án này một mình nếu không có sự tham khảo. Nên các bạn cứ tự nhiên @@... Miễn là hiểu code là được...

                                        
                                                    Đề tài:
                                                    
Đồ án của thầy bao gồm ba dạng cơ bảng trong 7 đề tài bên dưới, đó là Bài toán từ điển(B.1) , Bài toán xử lý đồ thị(B.7) và Bài toán quản lý(B.2 -> B.6).
 
1. Tra cứu từ điển: 
Tổ chức từ điển theo cấu trúc danh sách liên kết kép . Mỗi từ gồm có các
thông tin: Từ, loại từ, các nghĩa việt (theo cấu trúc danh sách tuyến tính, tối đa có 5 nghĩa
trên 1 từ) , các ví dụ (theo cấu trúc danh sách liên kết) .
Chương trình có các chức năng: nhập từ mới, hiệu chỉnh từ, xóa từ, tra từ theo 2 cách: nhập
đến đâu thì thanh sáng sẽ nhảy ngay đến từ đầu tiên có các ký tự đầu trùng với các ký tự vừa
nhập, hoặc dùng thanh sáng di chuyển đến từ cần tra, ghi từ vào file, load từ vào danh sách
liên kết kép…
Lưu ý: - Danh sách các từ được tổ chức theo cấu trúc mảng băm
- Các thuật toán xử lý trên từ điển đều thực hiện trong bộ nhớ trong . File chỉ là
nơi lưu các từ khi có sự thay đổi trên từ điển trong bộ nhớ trong.

2. Quản lý điểm sinh viên :
Ta tổ chức các danh sách sau:
- Danh sách môn học: cây nhị phân tìm kiếm (MAMH (C10) , TENMH, STCLT (số tín
chỉ lý thuyết), STCTH (số tín chỉ thực hành))
- Danh sách Lop : danh sách tuyến tính là 1 mảng con trỏ(MALOP (C15), TENLOP,
Năm nhập học, con trỏ dssv): con trỏ dssv sẻ trỏ đến danh sách sinh viên thuộc lớp đó.
- Danh sách sinh viên : danh sách liên kết đơn (MASV, HO, TEN, PHAI, SODT, con
trỏ): con trỏ sẻ trỏ đến danh sách điểm các môn của sinh viên đó
- Danh sách Điểm (danh sách liên kết đơn): ( MAMH, LAN, DIEM)
Chương trình có các chức năng sau :
a. NhapLop : cho phép cập nhật (thêm / xóa / hiệu chỉnh ) thông tin của lớp
b. In danh saùch Lôùp cuûa tröôøng theo 1 nieân khoùa naøo ñoù
c. NhapSV : Cập nhập sinh viên của 1 lớp: nhập vào mã lớp trước, sau đó nhập các sinh
viên vào lớp đó.
Lưu ý : Khi nhập liệu phải đủ 3 chức năng Thêm / Xóa / Hiệu chỉnh
Quá trình nhập SV mới sẽ dừng khi ta nhập vào mã sv là chuỗi rỗng.
d. In DSSV của 1 lớp (dựa vào mã lớp) theo thứ tự alphabet tăng dần của tên+họ ,
e. Nhập môn học: cho phép cập nhật (thêm / xóa / hiệu chỉnh ) thông tin của môn học
f. In DS môn học : tăng dần theo tên môn học.
g. Nhập điểm: User nhập vào mã lớp, mã môn học, lần thi. Căn cứ vào 3 giá trị này,
chương trình sẽ tự động lọc ra danh sách sv sẽ thi, và in ra màn hình danh sách theo dạng
sau :
                              STT MASV     HO      TEN DIEM
                              99  XXXX XXXXXXXXXXX XXXXX 5
                              99  XXXX XXXXXXXXXXX XXXXX 6
Bốn cột đầu đã có sẵn dữ liệu, lúc này user chỉ việc nhập điểm hoặc hiệu chỉnh điểm trực
tiếp vào khung.
h. In bảng điểm môn học của 1 lớp theo lần thi: User nhập vào mã lớp, mã môn học, lần
thi, chương trình sẽ in ra bảng điểm đã thi . Kết quả trên màn hình:
                                    BẢNG ĐIỂM MÔN HỌC
                              Lớp : <tenlop> Lần thi : 99
                              Môn học: <tenmon>
                              STT MASV HO          TEN  DIEM
                              99 XXXX XXXXXXXXXXX XXXXX 99
                              99 XXXX XXXXXXXXXXX XXXXX 99i.
In điểm trung bình kết thúc khóa học của 1 lớp theo số tín chỉ. Kết xuất:

                              BẢNG THỐNG KÊ ĐIỂM TRUNG BÌNH KHÓA HỌC
                                Lớp : <tenlop> Năm nhập học: 9999
                              STT MASV  HO TEN Điểm TB
                              99 XXXX XXXXXXXXXXX XXXXX 99.9
                              99 XXXX XXXXXXXXXXX XXXXX 99.9
j. Bảng điểm tổng kết các môn của các sinh viên thuộc 1 lớp(trong bảng điểm tổng kết 
chỉ hiển thị điểm thi lớn nhât từng môn của sinh vien) Kết xuất:
                                    BẢNG ĐIỂM TỔNG KẾT
                            Lớp : <tenlop> Năm nhập học: 9999
                    STT MãSV HọTên   Mã MH1 Mã MH2 Mã MH3 Mã MH4 Mã MH5 …….. Mã MHn
                      1 XXXX XXXXXXX   99     99     99     99     99    99     99
                      2 XXXX XXXXXXX   99     99     99     99     99    99      99
Lưu ý: Chương trình cho phép lưu các danh sách vào file; Kiểm tra các điều kiện khi
nhập làm dữ liệu bị sai.


3. Quản lý nhập xuất vật tư: Ta tổ chức các danh sách sau:
- Danh sách Vattu : cây nhị phân tìm kiếm ( MAVT (C10), TENVT, DVT, Số lượng tồn)
- Danh sách Nhanvien : danh sách tuyến tính là 1 mảng con trỏ (MANV, HO, TEN,
PHAI, con trỏ dshd): con trỏ dshd sẽ trỏ đến danh sách các hóa đơn mà nhân viên đó đã
lập. Danh sách nhân viên có tối đa 500 nhân viên
- Danh sách HOADON : danh sách liên kết đơn(SoHD (C20), Ngày lập hóa đơn, Loai,
con trỏ cthd). Lọai chỉ nhận ‘N’ (phiếu nhập) hoặc ‘X’ (phiếu xuất); con trỏ cthd sẻ trỏ
đến danh sách chi tiết các vật tư của hóa đơn đó.
- Danh sách CT_HOADON : danh sách liên kết đơn ( MAVT, Soluong, Dongia, %VAT).
Chương trình có các chức năng sau:
a/ Nhập vật tư : cho phép cập nhật (thêm / xóa / hiệu chỉnh ) thông tin của vật tư; riêng số
lượng tồn chỉ cho phép nhập khi đó là vật tư mới.
b/ In danh sách vật tư tồn kho : liệt kê ds vật tư ra màn hình theo thứ tự tên vật tư tăng dần.
Kết xuất : Mã VT Tên vật tư Đơn vị tính Số lượng tồn
c/ Nhập nhân viên: Cập nhập các nhân viên dựa vào mã nhân viên, họ, tên không được rỗng.
d/ In danh sách nhân viên theo thứ tự tên nhân viên tăng dần, nếu trùng tên thì tăng dần theo
họ ra màn hình, 1 nhân viên / dòng
e/ Lập hóa đơn nhập/Lập hóa đơn xuất: nhập vào số hóa đơn, ngày lập, loại (chỉ nhận ký tự N
hoặc X). Sau đó, tiếp tục cho phép nhập các vật tư của hóa đơn đó; Căn cứ vào loại hóa đơn,
chương trình sẽ tự động cập nhật số lượng tồn.
Lưu ý: - Nếu số lượng xuất không đủ hàng thì báo lỗi và in ra số lượng tồn hiện có trong
kho;
- Chỉ được phép xóa vật tư đang lập của hóa đơn hiện tại. Khi hóa đơn đã ghi
thì không được xóa các vật tư trog hóa đơn
f/ In hóa đơn : In hóa đơn dựa vào số hóa đơn do ta nhập vào
g/ Thống kê các hóa đơn trong 1 khỏang thời gian: nhập vào 2 thời điểm từ ngày , đến ngày,
chương trình sẽ in ra các hóa đơn được lập trong khoảng thời gian như trên. Kết xuất:
                    BẢNG LIỆT KÊ CÁC HÓA ĐƠN TRONG KHOẢNG THỜI GIAN
                      Từ ngày : ##/##/#### Đến ngày : ##/##/####
Số HĐ Ngày lập Loại HĐ Họ tên NV lập Trị giá hóa đơn
h/ In 10 vật tư có doanh thu cao nhất trong 1 khoảng thời gian.Lưu ý: Chương trình cho phép lưu các danh sách vào file; Kiểm tra các điều kiện khi nhập
làm dữ liệu bị sai.


4. Quản lý các chuyến bay nội địa thuộc 1 hăng hàng không: Ta toå chöùc caùc danh saùch
sau:
- Máy bay : danh sách tuyến tính (Số hiệu MB (C15), loại máy bay (C40), số chỗ) ; Mỗi máy
bay có 1 số hiệu duy nhất; số chỗ >=20
- Chuyến bay : danh sách liên kết đơn ( Mã CB (C15), Ngày giờ khởi hành, sân bay đến ,
trạng thái, Số hiệu MB, danh sách vé,). Mỗi chuyến bay có 1 mã duy nhất; trạng thái chuyến
bay bao gồm: 0: hủy chuyến, 1: còn vé, 2: hết vé,3: hoàn tất ; danh sách vé cho biết thông tin
vé trên chuyến bay, và số CMND của hành khách đã đặt vé đó. Mỗi vé có số vé là số thứ tự
trên chuyến từ số 1 đến số chỗ .
- Hành khách: cây nhị phân tìm kiếm (Số CMND , Ho, Ten, Phai)
Chöông trình coù caùc chöùc naêng sau:
a/ Caäp nhaäp danh saùch caùc maùy bay (theâm / xoùa / hieäu chænh)
b/ Caäp nhaät chuyeán bay: cho pheùp laäp chuyeán bay môùi, hieäu chænh ngaøy giôø khôûi
haønh cuûa chuyeán bay , huûy chuyeán.
c/Ñaët veù: cho pheùp ñaët veù treân 1 chuyeán bay; neáu thoâng tin haønh khaùch chöa coù thì
töï ñoäng caäp nhaät vaøo danh saùch haønh khaùch, neáu coù roài thì in ra maøn hình ñeå kieåm
tra. Moãi veù ñeàu phaûi ghi nhaän soá CMND cuûa haønh khaùch; neáu haønh khaùch chöa coù soá
CMND thì yeâu caàu nhaäp thoâng tin haønh khaùch tröôùc. Treân 1 chuyeán bay, moãi haønh
khaùch chæ ñöôïc mua 1 veù.
d/ In danh saùch caùc haønh khaùch thuoäc 1 chuyeán bay döïa vaøo maõ chuyeán bay. Keát
xuaát:
DANH SAÙCH HAØNH KHAÙCH THUOÄC CHUYEÁN BAY ######
Ngaøy giôø khôûi haønh: ##/##/####. Nôi ñeán : xxxxxxxxxxx
STT SOÁ VEÙ SOÁ CMND HOÏ TEÂN PHAÙI
e/ In danh saùch caùc chuyeán bay khôûi haønh trong ngaøy dd/mm/yyyy ñeán nôi XXXX maø
coøn veù ( cho bieát cuï theå soá löôïng caùc veù coøn troáng)
f/ In danh saùch caùc veù coøn troáng cuûa 1 chuyeán bay coù maõ chuyeán bay laø X.
g/ Thoáng keâ soá löôït thöïc hieän chuyeán bay cuûa töøng maùy bay theo thöù töï soá löôït thöïc
hieän giaûm daàn. Keát xuaát:
Soá hieäu maùy bay Soá löôït thöïc hieän chuyeán bay
Lưu ý: Chương trình cho phép lưu các danh sách vào file; Kiểm tra các điều kiện khi nhập
liệu làm dữ liệu bị sai.


5. Thư Viên: Ta tổ chức các danh sách sau:
- Đầu sách : danh sách tuyến tính là 1 mảng con trỏ (ISBN , Tên sách, Số trang, Tác giả, thể loại, con trỏ): con trỏ sẽ trỏ đến các sách thuộc đầu sách tương ứng
- Danh Mục Sách : Danh sách  liên kết đơn( Mã sách, trangj thái, vị trí ). Mỗi cuốn sách 
chỉ có 1 mã duy nhất; trạng thái của sách bao gồm: 0: cho mươn được, 1: đã có độc giả mượn, 2: sách đã thanh lý
- Danh Sách độc giả: cây nhị phân tìm kiếm (MADG (soá nguyeân ngẫu nhiên tự động),
Ho, Ten, Phai, trạng thái thẻ, con trỏ): con trỏ sẽ trỏ đến danh sách các cuốn sách đã và đang mượn
Chương trình có các chức năng sau: 
a. Nhập độc giả: thêm / xóa / hiệu chỉnh thông tin độc giả. Mã độc giả được chương trình tự
động lấy ngẫu nhiên và không trùng với các mã độc giả cũ; Phái chỉ nhận ‘Nam’ hoặc ‘Nữ’;
trạng thái thẻ = 0 khi thẻ bị khóa, trạng thái thẻ = 1 khi thẻ đang hoạt động (được quyền
mượn sách).
b. In danh sách độc giả : in ra màn hình theo thứ tự tên+họ tăng dần hoặc theo thứ tự mã độc
giả tăng dần theo yêu của thủ thư.
c. Nhập đầu sách và đánh mã sách tự động
d. In danh sách các đầu sách trong thư viện theo thứ tự tên sách tăng dần.
e. Tìm thông tin sách dựa vào tên sách : in ra các thông tin mã ISBN, tên sách, tác giả, năm
xuất bản, thể loại, các mã sách còn có trong thư viện.
f. Mượn sách : nhập vào mã độc giả, chương trình sẽ liệt kê các sách mà độc giả đang mượn.
Mỗi độc giả chỉ được mượn tối đa 3 cuốn, không cho mượn khi giữ 1 sách quá hạn (15 ngày)
g. Trả sách
h. Liệt kê danh sách các sách mà 1 độc giả đang mượn
i. In danh sách độc giả mượn sách quá hạn theo thứ tự thời gian quá hạn giảm dần
j. In 10 sách có số lượt mượn nhiều nhất.

6. Thi trắc nghiệm:
- Danh sách môn học: danh sách liên kết(MAMH, TENMH).
- Danh sách Lớp:  danh sách tuyến tính(MALOP, TENLOP, con trỏ); con trỏ sẻ trỏ đến danh sách
sinh viên thuộc lớp đó.
- Danh sách sinh viên: danh sách liên kết đơn(MASV, HO, TEN, PHAI, password, con trỏ): con trỏ
sẽ trỏ đến điểm cac môn đã thi trắc nghiệm.
- Danh sách điểm thi( Danh sách liên kết đơn ) (Mamh, Diem)
- Dạnh sách Câu hỏi thi(cây nhị phân tìm kiếm cân bằng với key = Id) (Id, mã MH, Nội dung)
, A, B, C, D, Đáp án); trong đó A, B, C, D là 4 lựa chọn tương ứng với nội dung câu hỏi.
Chương trình có các chức năng sau: Đăng nhậ dựa vào mã sinh viên, password. Nếu tài khoản đăng nhập
là GV , pass là GV thì sẽ có toàn quyền , Nhập lớp , In ds lớp. Nhập sinh viên của lớp, Nhập môn học
. Nhập câu hỏi thi(Id là số ngẫu nhiên do chuong trình tụ tạo), Thi trắc nghiệm(trước khi thi hỏi
) người thi môn thi, số câu hỏi thi, số phút thi - sau đó lấy ngẫu ngiên các câu hỏi trong dan sách
câu hỏi ti của môn; In chi tiết cac câu hỏi đã thi 1 môn học của 1 sinh viên , In bảng điểm thi trắc
nghiệm môn học của 1 lớp(nếu có sinh viên chưa ti thì ghi " Chưa thi")
Lưu ý: Chương trình cho phép lưu các danh sách vào file: kiểm tra các điều kiện làm dữ liệu bị sai.
Sinh viên có thể tự thiết kế thêm danh sách để đáp ứng yêu cầu của đề tài .

7. Đồ thị: Viết chương trình cho phép:
- Nhập đồ thị có hướng có trọng số qua giao diện, có thể thêm, xóa sửa lại đỉnh, cung, trọng số
(trên màn hình hiển thị ma trận kề tương ứng). Lưu đồ thi vào file sao cho ta có thể vẽ lại đồ thị 
về sau này.
- Demo giải thuật DFS, BFS.
- Tính số thành phần liên thông của đồ thị ? Và liệt kê các đỉnh trong từng thành phần liên thông
- Tìm đường đi ngắn nhât từ đỉnh X đến đỉnh Y,, có demo trên hình và in ra đường đi cụ thể
- Tìm tất cả các đỉnh trụ , đỉnh thắt và cạnh cầu của đồ thị.
- Tìm các chun trình Hamilton và chu trình Euler của đồ thị (nếu có).
- Demo thuật toán Topo Sort
- Demo bài toán Tô màu đồ thị
