
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8663);
        set_picid_2(8663);

        set_level(70);
        set_value(53000);
        set_max_lasting(5599);
        set("cp", 130);
        set("pp", 75);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
