import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * @ClassName Test
 * @Deacription
 * @Author DeepBlue
 * @Date 2021/2/6 18:01
 * @Version 1.0
 **/
public class Test {
//    @org.junit.jupiter.api.Test
//    public void test() {
//        Lock lock = new ReentrantLock();
//        final Integer[] i = {1};
//        CountDownLatch latch = new CountDownLatch(1);
//        Thread thread1 = new Thread(() -> {
//            for (int j = 0; j < 10; j++) {
//                lock.lock();
//                i[0]++;
//                lock.unlock();
//                try {
//                    TimeUnit.MILLISECONDS.sleep(20);
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//            }
//        });
//        Thread thread = new Thread(() -> {
//            while (true) {
//                lock.lock();
//                System.out.println(i[0]);
//                lock.unlock();
//            }
//        });
//        try {
//            thread1.join();
//            thread.join();
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }
//        thread.start();
//        thread1.start();
//        try {
//            latch.await();
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }
//    }
}
