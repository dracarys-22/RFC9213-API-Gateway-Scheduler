# RFC 9213 Uyumlu API Gateway İstek Zamanlayıcısı

Bu proje, bir API Gateway sistemine gelen HTTP isteklerini **RFC 9213 (Extensible HTTP Priorities)** standardına uygun şekilde parse eden ve **Min-Heap** veri yapısını kullanarak önceliklendiren bir simülasyondur.

#  Proje Amacı
Yoğun trafik alan sistemlerde isteklerin "Urgency" (Aciliyet) değerine göre sıraya dizilmesi kritik bir öneme sahiptir. Bu projede, sıradan diziler yerine $O(\log n)$ karmaşıklığı sunan Min-Heap yapısı kullanılarak yüksek verimli bir zamanlayıcı geliştirilmiştir.

#  Yazılım Mimarisi
Proje, C dilinin modülerlik prensiplerine uygun olarak 3 ana katmanda inşa edilmiştir:
- **RFC Parser:** HTTP header içindeki öncelik değerlerini ayrıştırır.
- **Min-Heap Engine:** Öncelikli kuyruk (Priority Queue) mantığını yönetir.
- **Scheduler (Main):** Sistemin giriş ve çıkış noktasıdır.

# Derleme ve Çalıştırma
Projeyi GCC derleyicisi ile şu komutu kullanarak derleyebilirsiniz:

```bash
gcc main.c rfc_parser.c min_heap.c -o gateway
./gateway
