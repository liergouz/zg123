
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("ϸ�޲���");
        set_picid_1(6123);
        set_picid_2(6123);

        set_level(15);
        set_value(1350);
        set_max_lasting(6699);
        set("dp", 24);
        set("pp", 0);

        setup();

        set_gender(2);
        set_armor_code(21);
}

// ��������ȡ����
string get_desc()
{
        return "ϸ�޲���";
}
