
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8703);
        set_picid_2(8703);

        set_level(15);
        set_value(1250);
        set_max_lasting(6199);
        set("dp", 18);
        set("pp", 3);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
