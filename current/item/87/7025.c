
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8705);
        set_picid_2(8705);

        set_level(25);
        set_value(6250);
        set_max_lasting(5499);
        set("dp", 13);
        set("pp", 27);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
