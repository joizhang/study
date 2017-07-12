#include <stdio.h>
#define XMAX 10
#define YMAX 10
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point
{
	int x;
	int y;
};
struct  rect
{
	struct point pt1;
	struct point pt2;
};

struct point makepoint(int x, int y) 
{
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

struct point addpoint(struct point p1, struct point p2) 
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

int ptinrect(struct point p, struct rect r) 
{
	return p.x >= r.pt1.x && p.x < r.pt2.x
		&& p.y >= r.pt1.y && p.y < r.pt2.y; 
}

struct rect cannonrect(struct rect r)
{
	struct rect temp;
	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}

int main(int argc, char const *argv[])
{

	struct point pt = {320, 200};/* code */
	printf("%d, %d\n", pt.x, pt.y);

	struct point pt1 = makepoint(1, 2);
	printf("%d, %d\n", pt1.x, pt1.y);

	struct rect screen;
	struct point middle;
	screen.pt1 = makepoint(0, 0);
	screen.pt2 = makepoint(XMAX, YMAX);
	middle = makepoint((screen.pt1.x + screen.pt2.x)/2, (screen.pt1.y + screen.pt2.y)/2);
	printf("%d, %d\n", middle.x, middle.y);

	printf("%d\n", ptinrect(makepoint(30, 40), screen));

	struct point origin, *pp;
	origin = makepoint(0, 1);
	pp = &origin;
	printf("struct pointer: %d, %d\n", pp->x, pp->y);

	char c1 = 'c';
	struct{
		int len;
		char *str;
	} stc = {1, &c1}, *p;
	p = &stc;
	/*stc.len = 1;
	stc.str = &c1;*/
	//stc = {1, &c1}; //error
	//*p = {1, "hello"};
	printf("%d\n", p->len);//1
	printf("%d\n", ++p->len);//2
	printf("%d\n", p++->len);//2
	printf("%d\n", p->len);
	printf("%d\n", p->len);//not 3 but 0 ?
	return 0;
}

