
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6074);
        set_picid_2(6074);

        set_level(25);
        set_value(3000);
        set_max_lasting(7299);
        set("dp", 58);
        set("pp", 32);

        setup();

        set_gender(1);
        set_armor_code(1);
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
