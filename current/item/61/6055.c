
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("������ȹ");
        set_picid_1(6154);
        set_picid_2(6154);

        set_level(55);
        set_value(26500);
        set_max_lasting(9099);
        set("dp", 77);
        set("pp", 139);

        setup();

        set_gender(2);
        set_armor_code(24);
}

// ��������ȡ����
string get_desc()
{
        return "������ȹ";
}
