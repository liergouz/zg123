
#include <equip.h>

inherit ITEM;
inherit "/inh/equip/equip";

private static int Gender;              // �Ա��־
private static int Type1;               // ���δ���1
private static int Type2;               // ���δ���2
private static int Color1;              // ����1��ɫ(ɫ�룲��ɫ�룱)
private static int Color2;              // ����2��ɫ(ɫ�룴��ɫ�룳)

// ��������ȡ�Ա��־
int get_gender() { return Gender; }

// �����������Ա��־
int set_gender( int flag ) { return Gender = flag; }

int get_back_type() {return Type1;}

int set_back_type(int i) {return Type1 = i;}

int get_back2_type() {return Type2;}

int set_back2_type(int i) {return Type2 = i;}

int get_back_color() {return Color1;}

int set_back_color(int i) {return Color1 = i;}

int get_back2_color() {return Color2;}

int set_back2_color(int i) {return Color2 = i;}

int get_equip_type() { return BACK_TYPE; }
