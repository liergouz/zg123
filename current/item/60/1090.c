
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(6040);
        set_picid_2(6040);

        set_level(90);
        set_value(50500);
        set_max_lasting(28599);
        set("dp", 219);
        set("pp", 130);

        setup();

        set_gender(1);
        set_armor_code(6);
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
