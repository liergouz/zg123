
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("��ͷ��ȹ");
        set_picid_1(6174);
        set_picid_2(6174);

        set_level(45);
        set_value(18500);
        set_max_lasting(7899);
        set("dp", 65);
        set("pp", 115);

        setup();

        set_gender(2);
        set_armor_code(23);
}

// ��������ȡ����
string get_desc()
{
        return "��ͷ��ȹ";
}
