
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("̤����");
        set_picid_1(6034);
        set_picid_2(6034);

        set_level(60);
        set_value(28500);
        set_max_lasting(19599);
        set("dp", 143);
        set("pp", 91);

        setup();

        set_gender(1);
        set_armor_code(4);
}

// ��������ȡ����
string get_desc()
{
        return "̤����";
}
