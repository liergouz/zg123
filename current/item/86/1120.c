
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8662);
        set_picid_2(8662);

        set_level(120);
        set_value(76500);
        set_max_lasting(9699);
        set("cp", 0);
        set("pp", 120);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
