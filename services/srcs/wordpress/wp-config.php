<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', 'pass' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql-svc' ); ////////////////////////////////////////////

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );


/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'tx0)Am6d3W>DKRV6.JkC`-xQdv`rVd$P;FxnEKSYr`EQx(ZsK4I]*7S9H/3[h]J/');
define('SECURE_AUTH_KEY',  '^MHY}7xePU+;=XLl.s=CxYmxq=a-R:c.eSN,}D*vN>L3T4B|m81q3b_B_E)n.-P~');
define('LOGGED_IN_KEY',    'Z#EWGx*%cId*Lz[tQ] *7u?.F8UK.QwyF:+drg7@s;SqsunAC#fg[?S034nB#=WM');
define('NONCE_KEY',        'UD>9c8sOY:M-:^)HZ~ec#|mg_6|c;]S~:W,@jS;@p [%I;,_i9-}>F^nUWo0G%6~');
define('AUTH_SALT',        'GH*%e*(1w5xZ &hOd&}L?0y!E-8+A]!!R>rN37v)*z0-t}c.lzLKj;N$3{}J1!0E');
define('SECURE_AUTH_SALT', 'qD^?I(%|+SuG0$3f;x:3?,f+WCvZaZfQ&!ts#[71+%or%7`9>wt=p;,OpmVvw*Px');
define('LOGGED_IN_SALT',   '<}/odA0}|m=2nv9BJ%@sy~ 8}Q~-h$R&$Rm:8+@hfecb+|Vqo]R[<)f?_DOS`tAW');
define('NONCE_SALT',       '^v[%x_;(Op[6GaY]-%k|TP(|`Gq&s4#2IY4M6TX1lLRmb~gV:{*xR-lWp/P:!(nG');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
