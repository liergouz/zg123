
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8703);
        set_picid_2(8703);

        set_level(15);
        set_value(2250);
        set_max_lasting(5899);
        set("dp", 5);
        set("pp", 5);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
