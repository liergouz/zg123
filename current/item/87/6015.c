
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8703);
        set_picid_2(8703);

        set_level(15);
        set_value(2750);
        set_max_lasting(5199);
        set("dp", 0);
        set("pp", 15);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
