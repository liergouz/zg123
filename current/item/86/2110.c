
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8662);
        set_picid_2(8662);

        set_level(110);
        set_value(69500);
        set_max_lasting(9399);
        set("cp", 0);
        set("pp", 115);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
