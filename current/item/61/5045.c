
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("��ˮ��ȹ");
        set_picid_1(6174);
        set_picid_2(6174);

        set_level(45);
        set_value(18500);
        set_max_lasting(7899);
        set("dp", 67);
        set("pp", 115);

        setup();

        set_gender(2);
        set_armor_code(23);
}

// ��������ȡ����
string get_desc()
{
        return "��ˮ��ȹ";
}
