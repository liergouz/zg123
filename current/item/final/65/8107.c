
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 8; }

// ��������Ʒ���
int get_fin_type() { return 2373; }

// ���������촦��
void create()
{
        set_name("����ս��");
        set_picid_1(6582);
        set_picid_2(6582);

        set_level(107);
        set_value(1000);
        set_max_lasting(23899);
        set("ap", 0);
        set("dp", 205);
        set("cp", 0);
        set("pp", 58);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ս��";
}
