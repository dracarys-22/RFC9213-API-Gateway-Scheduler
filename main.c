#include <stdio.h>
#include "rfc_parser.h"
#include "min_heap.h" 

int main() {
    // 1. Min-Heap (Kuyruk) oluştur (Örn: 10 kapasiteli)
    MinHeap* queue = create_heap(10);

    printf("--- Istekler Sisteme Geliyor ---\n");
    
    // 2. Farklı istekleri parser ile okuyup kuyruğa ekle
    insert_request(queue, parse_priority("u=5"));     // Düşük öncelik
    insert_request(queue, parse_priority("u=1, i"));  // Çok Yüksek öncelik
    insert_request(queue, parse_priority("u=3"));     // Orta öncelik
    insert_request(queue, parse_priority("u=2"));     // Yüksek öncelik

    // 3. İstekleri öncelik sırasına göre kuyruktan çıkar (API Gateway mantığı)
    printf("\n--- Istekler Isleniyor (Min-Heap Siralamasi) ---\n");
    while (queue->size > 0) {
        Priority p = extract_min(queue);
        printf("Islenen Istek -> Urgency: %d, Incremental: %d\n", p.urgency, p.incremental);
    }

    // 4. Bellek sızıntısı olmaması için malloc ile açılan yerleri temizle (Free)
    free_heap(queue);

    return 0;
}