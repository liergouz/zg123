
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8600);
        set_picid_2(8600);

        set_level(30);
        set_value(17000);
        set_max_lasting(4999);
        set("cp", 50);
        set("pp", 35);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
