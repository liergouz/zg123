
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(6080);
        set_picid_2(6080);

        set_level(70);
        set_value(36500);
        set_max_lasting(22599);
        set("dp", 170);
        set("pp", 100);

        setup();

        set_gender(1);
        set_armor_code(5);
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
