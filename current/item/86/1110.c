
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8663);
        set_picid_2(8663);

        set_level(110);
        set_value(69500);
        set_max_lasting(9399);
        set("cp", 0);
        set("pp", 110);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
