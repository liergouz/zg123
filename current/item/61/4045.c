
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("׷����ȹ");
        set_picid_1(6174);
        set_picid_2(6174);

        set_level(45);
        set_value(15000);
        set_max_lasting(14799);
        set("dp", 95);
        set("pp", 60);

        setup();

        set_gender(2);
        set_armor_code(23);
}

// ��������ȡ����
string get_desc()
{
        return "׷����ȹ";
}
