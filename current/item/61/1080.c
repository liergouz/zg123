
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("���Ʋ���");
        set_picid_1(6160);
        set_picid_2(6160);

        set_level(80);
        set_value(43500);
        set_max_lasting(25599);
        set("dp", 187);
        set("pp", 116);

        setup();

        set_gender(2);
        set_armor_code(26);
}

// ��������ȡ����
string get_desc()
{
        return "���Ʋ���";
}
