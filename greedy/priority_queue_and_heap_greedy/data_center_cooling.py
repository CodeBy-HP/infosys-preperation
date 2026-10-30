import sys
import heapq

class DataCenterCooling:
    def __init__(self, n: int, d: int, heat_array: list):
        self.n = n
        self.d = d
        self.H = list(heat_array)

    def update(self, pos: int, value: int):
        if 0 <= pos < self.n:
            self.H[pos] = value

    def query(self, l: int, r: int, k: int, critical: int) -> int:
        # Min-heap simulating max-heap by negating heat values:
        # heapq pops most negative (-heat) first (i.e. largest heat).
        # In case of ties, smaller index is popped first.
        pq = [(-self.H[i], i) for i in range(l, r + 1)]
        heapq.heapify(pq)

        invalidated = [False] * self.n
        query_reduction = 0
        selected_count = 0

        while pq and selected_count < k:
            neg_heat, idx = heapq.heappop(pq)
            heat = -neg_heat

            if invalidated[idx]:
                continue

            selected_count += 1
            if heat >= critical:
                query_reduction += heat * 4
            else:
                query_reduction += heat

            # Invalidate all indices in [idx - d + 1, idx + d - 1]
            start_idx = max(0, idx - self.d + 1)
            end_idx = min(self.n - 1, idx + self.d - 1)
            for i in range(start_idx, end_idx + 1):
                invalidated[i] = True

        return query_reduction


def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        # Example demonstration run
        system = DataCenterCooling(3, 2, [5, 5, 5])
        ans = system.query(0, 2, 3, 0)
        print(f"Sample Query Output: {ans} (Expected: 40)")
        return

    iterator = iter(input_data)
    n = int(next(iterator))
    d = int(next(iterator))
    arr = [int(next(iterator)) for _ in range(n)]
    q = int(next(iterator))

    system = DataCenterCooling(n, d, arr)
    total = 0

    for _ in range(q):
        type_op = int(next(iterator))
        if type_op == 1:
            pos = int(next(iterator))
            val = int(next(iterator))
            system.update(pos, val)
        else:
            l = int(next(iterator))
            r = int(next(iterator))
            k = int(next(iterator))
            critical = int(next(iterator))
            total += system.query(l, r, k, critical)

    print(total)


if __name__ == '__main__':
    main()

