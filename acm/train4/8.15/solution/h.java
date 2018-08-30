import static java.lang.Math.*;
import java.util.*;

public class h {
  final static String IMPOSSIBLE = "impossible";
  final static double EP = 0.0000001;
  static boolean eq(double a, double b) { return abs(a-b) <= EP; }
  
  static class P {
    final double x, y;
    P(double x, double y) {
      this.x = x;
      this.y = y;
    }
    double dist(P that) {
      return sqrt(dist2(that));
    }
    double dist2(P that) {
      return (this.x - that.x) * (this.x - that.x) + (this.y - that.y) * (this.y - that.y);
    }
  }
  static P P(double x, double y) { return new P(x, y); }
  static class C {
    final double x, y, r;
    final P cp;
    C(double x, double y, double r) {
      this.x = x;
      this.y = y;
      this.r = r;
      this.cp = P(x, y);
    }
    boolean contains(C that) {
      return cp.dist(that.cp) + that.r <= r;
    }
    private double heron(double a, double b, double c) {
      double s = (a + b + c) / 2;
      return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    private double lc(double a, double b, double c) {
      return (a * a + b * b - c * c) / (2 * a * b);
    }
    double intersec(C that) {
      if (!isCrossing(that)) return 0.0;
      double d = this.cp.dist(that.cp);
      double coa = lc(this.r, d, that.r);
      double tha = acos(coa);
      double sa = tha * this.r * this.r;
      double cob = lc(that.r, d, this.r);
      double thb = acos(cob);
      double sb = thb * that.r * that.r;
      double sc = heron(this.r, that.r, d) * 2;
      return sa + sb - sc;
    }
    boolean isCrossing(C that) {
      return this.cp.dist2(that.cp) <= (this.r + that.r)*(this.r + that.r);
    }
    @Override public String toString() {
      return String.format("%.9f %.9f %.9f", x, y, r);
    }
  }
  static C C(double x, double y, double r) { return new C(x, y, r); }
  static C[] solve(int w, int h, int a, int b, int c) {
    assert (a >= b);
    double ra = sqrt(a / PI);
    double rb = sqrt(b / PI);
    if (ra * 2 >= w || ra * 2 >= h)
      return null;
    else if (b == c) 
      return new C[]{C(w / 2.0, h / 2.0, ra), C(w / 2.0, h / 2.0, rb)};
    else if (c == 0)
      if (ra + ra * sqrt(2) + rb + rb * sqrt(2) >= sqrt(h*h+w*w))
        return null;
      else
        return new C[]{C(ra, ra, ra), C(w-rb, h-rb, rb)};
    else {
      C ca = C(ra, ra, ra);
      C lb = C(ra, ra, rb);
      C hb = C(w - rb, h - rb, rb);
      if (ca.intersec(hb) > c) return null;
      while (true) {
        C cb = C((lb.x + hb.x) / 2, (lb.y + hb.y) / 2, hb.r);
        if (ca.contains(cb)) {
          lb = cb;
          continue;
        }
        double s = ca.intersec(cb);
        if (eq(s, c))
          return new C[]{ca, cb};
        else if (s < c)
          hb = cb;
        else
          lb = cb;
      }
    }
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (sc.hasNextInt()) {
      int w = sc.nextInt();
      int h = sc.nextInt();
      int a = sc.nextInt();
      int b = sc.nextInt();
      int c = sc.nextInt();
      if (w == 0 && h == 0 && a == 0 && b == 0 && c == 0) break;
      if (a >= b) {
        C[] res = solve(w, h, a, b, c);
        if (res == null)
          println(IMPOSSIBLE);
        else
          println(res[0] + " " + res[1]);
      }
      else {
        C[] res = solve(w, h, b, a, c);
        if (res == null)
          println(IMPOSSIBLE);
        else
          println(res[1] + " " + res[0]);
      }
    }
  }
  static void println(Object o) { System.out.println(o); }
}
