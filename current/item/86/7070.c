
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8659);
        set_picid_2(8659);

        set_level(70);
        set_value(53000);
        set_max_lasting(5599);
        set("cp", 130);
        set("pp", 80);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
