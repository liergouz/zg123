
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8713);
        set_picid_2(8713);

        set_level(40);
        set_value(7500);
        set_max_lasting(8499);
        set("dp", 40);
        set("pp", 25);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
