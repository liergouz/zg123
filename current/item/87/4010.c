
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

        set_level(10);
        set_value(1100);
        set_max_lasting(5799);
        set("dp", 2);
        set("pp", 2);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
