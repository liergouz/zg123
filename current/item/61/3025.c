
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("ս��ȹ");
        set_picid_1(6174);
        set_picid_2(6174);

        set_level(25);
        set_value(3000);
        set_max_lasting(9099);
        set("dp", 71);
        set("pp", 37);

        setup();

        set_gender(2);
        set_armor_code(21);
}

// ��������ȡ����
string get_desc()
{
        return "ս��ȹ";
}
