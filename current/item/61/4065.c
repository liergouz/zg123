
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��Ƥ����");
        set_picid_1(6140);
        set_picid_2(6140);

        set_level(65);
        set_value(27000);
        set_max_lasting(22299);
        set("dp", 132);
        set("pp", 88);

        setup();

        set_gender(2);
        set_armor_code(25);
}

// ��������ȡ����
string get_desc()
{
        return "��Ƥ����";
}
