
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 2256; }

// ���������촦��
void create()
{
        set_name("����ͷ��");
        set_picid_1(6556);
        set_picid_2(6556);

        set_level(105);
        set_value(11000);
        set_max_lasting(26899);
        set("ap", 0);
        set("dp", 185);
        set("cp", 0);
        set("pp", 67);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ͷ��";
}
