
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("�������");
        set_picid_1(6180);
        set_picid_2(6180);

        set_level(90);
        set_value(42000);
        set_max_lasting(31599);
        set("dp", 167);
        set("pp", 123);

        setup();

        set_gender(2);
        set_armor_code(26);
}

// ��������ȡ����
string get_desc()
{
        return "�������";
}
